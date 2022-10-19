#include <bits/stdc++.h>

using namespace std;

bool gl(char c) {
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    return false;
}

bool check_mistake(char a, char b, char c) {
    if (gl(a) || gl(b) || gl(c))
        return false;
    if (a == b && a == c && b == c)
        return false;
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << s[0];
    if (s.size() > 1)
        cout << s[1];
    bool has_space = false;
    for (int i = 2; i < s.size(); ++i) {
        if (!has_space && check_mistake(s[i], s[i - 1], s[i - 2])) {
            has_space = true;
            cout << ' ';
        } else
            has_space = false;
        cout << s[i];
    }
}