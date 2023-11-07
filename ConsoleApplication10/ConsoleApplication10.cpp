#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num, int denom) : numerator(num), denominator(denom) {
    }

    Fraction operator+(int value) const {
        return Fraction(numerator + value * denominator, denominator);
    }

    Fraction operator+(double value) const {
        return Fraction(numerator + static_cast<int>(value * denominator), denominator);
    }
};

Fraction operator+(int value, const Fraction& fraction) {
    return fraction + value;
}

Fraction operator+(double value, const Fraction& fraction) {
    return fraction + value;
}

class Student {
public:
    double averageGrade;
    string name;

    Student() : name(""), averageGrade(0.0) {  // Конструктор по умолчанию
    }

    Student(const string& studentName, double avg) : name(studentName), averageGrade(avg) {
    }

    bool operator==(const Student& other) const {
        return averageGrade == other.averageGrade;
    }

    bool operator!=(const Student& other) const {
        return !(*this == other);
    }

    bool operator>(const Student& other) const {
        return averageGrade > other.averageGrade;
    }

    bool operator<(const Student& other) const {
        return averageGrade < other.averageGrade;
    }
};

class Group {
public:
    int numberOfStudents;
    string name;
    int course;
    string startStudyDate;
    Student* students;

    Group(int count) : numberOfStudents(count), students(nullptr) {
    }

    bool operator==(const Group& other) const {
        return numberOfStudents == other.numberOfStudents;
    }

    bool operator!=(const Group& other) const {
        return !(*this == other);
    }

    operator string() const {
        return "Группа " + name + ", " + to_string(course) + " курс, дата начала обучения " + startStudyDate;
    }

    void SetName(const string& groupName) {
        name = groupName;
    }

    void SetCourse(int groupCourse) {
        course = groupCourse;
    }

    void SetStartStudyDate(int day, int month, int year) {
        startStudyDate = to_string(day) + "." + to_string(month) + "." + to_string(year);
    }

    void AddStudent(const Student& student) {
        if (students == nullptr) {
            students = new Student[1];
            students[0] = student;
        }
        else {
            Student* newStudents = new Student[numberOfStudents + 1];
            for (int i = 0; i < numberOfStudents; i++) {
                newStudents[i] = students[i];
            }
            newStudents[numberOfStudents] = student;

            delete[] students;
            students = newStudents;
        }

        numberOfStudents++;
    }

    ~Group() {
        delete[] students;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Fraction fraction1(1, 2);
    Fraction fraction2(1, 3);

    Fraction result = fraction1 + 3;
    cout << "Fraction + int: " << result.numerator << "/" << result.denominator << endl;

    result = 5 + fraction2;
    cout << "int + Fraction: " << result.numerator << "/" << result.denominator << endl;

    result = fraction1 + 0.25;
    cout << "Fraction + double: " << result.numerator << "/" << result.denominator << endl;

    result = 1.5 + fraction2;
    cout << "double + Fraction: " << result.numerator << "/" << result.denominator << endl;

    Student student1;  // Используем конструктор по умолчанию
    student1.name = "Alice";  // Устанавливаем имя
    student1.averageGrade = 85.5;

    Student student2("Bob", 90.0);

    if (student1 == student2) {
        cout << "Students are equal." << endl;
    }
    else {
        cout << "Students are not equal." << endl;
    }

    if (student1 != student2) {
        cout << "Students are not equal." << endl;
    }
    else {
        cout << "Students are equal." << endl;
    }

    if (student1 > student2) {
        cout << "Student 1 has a higher grade." << endl;
    }
    else if (student1 < student2) {
        cout << "Student 2 has a higher grade." << endl;
    }
    else {
        cout << "Students have the same grade." << endl;
    }

    Group group1(30);
    Group group2(25);

    group1.SetName("KND-221");
    group1.SetCourse(2);
    group1.SetStartStudyDate(1, 9, 2022);

    Student student("Alex", 88.5);
    group1.AddStudent(student);

    if (group1 == group2) {
        cout << "Groups have the same number of students." << endl;
    }
    else {
        cout << "Groups have different numbers of students." << endl;
    }

    if (group1 != group2) {
        cout << "Groups have different numbers of students." << endl;
    }
    else {
        cout << "Groups have the same number of students." << endl;
    }

    string groupInfo = static_cast<string>(group1);
    cout << groupInfo << "\n";

    return 0;
}
