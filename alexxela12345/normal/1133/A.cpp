#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int h1 = stoi(s1.substr(0, 2));
    int m1 = stoi(s1.substr(3, 2));
    int h2 = stoi(s2.substr(0, 2));
    int m2 = stoi(s2.substr(3, 2));
    int start = 60 * h1 + m1;
    int end = 60 * h2 + m2;
    int mid = start + (end - start) / 2;
    cout << mid / 60 / 10 << mid / 60 % 10 << ":" << mid % 60 / 10 << mid % 60 % 10 << endl;
    return 0;
}