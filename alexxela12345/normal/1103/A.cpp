#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool b1 = false, b2 = false;
    for (char c : s) {
        if (c == '0') {
            if (b1) {
                cout << "3 1" << endl;
                b1 = false;
            } else {
                cout << "1 1" << endl;
                b1 = true;
            }
        } else {
            if (b2) {
                cout << "4 1" << endl;
                b2 = false;
            } else {
                cout << "4 3" << endl;
                b2 = true;
            }
        }
    }
    return 0;
}