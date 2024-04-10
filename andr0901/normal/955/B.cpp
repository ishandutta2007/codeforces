#include <iostream>
#include <vector>

using namespace std;


bool f (vector <char> a, char c) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == c) return 1;
    }
    return 0;
}

int main()
{
    vector <char> a;
    vector <int> b;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (f(a, s[i]) == 0) {
            if (a.size() == 4) {
                cout << "No";
                return 0;
            }
            else {
                a.push_back(s[i]);
                b.push_back(1);
            }
        }
        else {
            for (int j = 0; j < a.size(); j++) {
                if (a[j] == s[i]) b[j]++;
            }
        }
    }
    if (s.size() < 4) cout << "No";
    else if (a.size() == 1) cout << "No";
    else if (a.size() == 2) {
        if (b[0] == 1 || b[1] == 1) {
            cout << "No";
        }
        else cout << "Yes";
    }
    else cout << "Yes";
    return 0;
}