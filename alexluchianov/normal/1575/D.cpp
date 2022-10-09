#include <bits/stdc++.h>

using namespace std;

int pow10(int e) {
    int ret = 1;
    for(int i = 0; i < e; i++) {
        ret *= 10;
    }

    return ret;
}

string s;

int count_ = 0;
int countx = 0;

int match(string last2) {
    int x1 = -1, x2 = -1;

    if(s[s.size() - 1] == 'X') {
        x1 = last2[1];
    }
    if(s[s.size() - 2] == 'X') {
        x2 = last2[0];
    }

    if(s[s.size() - 1] != 'X' && s[s.size() - 1] != '_' && s[s.size() - 1] != last2[1]) {
        return 0;
    }
    if(s[s.size() - 2] != 'X' && s[s.size() - 2] != '_' && s[s.size() - 2] != last2[0]) {
        return 0;
    }

    if(x1 != -1 && x2 != -1 && x1 != x2) {
        return 0;
    }
    if(x1 == -1 && x2 == -1) {
        return pow10(count_) * (s[0] == '_' ? 9 : 1) * (countx >= 1 ? (s[0] == 'X' ? 9 : 10) : 1);
    }

    if(x1 != -1) x2 = x1;
    if(x2 != -1) x1 = x2;

    return pow10(count_) * (s[0] == '_' ? 9 : 1) * (s[0] == 'X' ? (x1 == '0' ? 0 : 1) : 1);
}

int main() {
    cin >> s;

    if(s.size() == 1) {
        if(s[0] == '0') {
            cout << 1 << endl;
        }
        else if(s[0] == 'X') {
            cout << 1 << endl;
        }
        else if(s[0] == '_') {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }

        return 0;
    }

    if(s.size() == 2) {
        if(s[0] == '_' && s[1] == '_') {
            cout << 3 << endl;
            return 0;
        }
        if(s[0] == '_' && s[1] == '5') {
            cout << 2 << endl;
            return 0;
        }
        if(s[0] == '_' && s[1] == 'X') {
            cout << 3 << endl;
            return 0;
        }
        if(s[0] == '_' && s[1] == '0') {
            cout << 1 << endl;
            return 0;
        }
        if(s[0] == '_') {
            cout << 0 << endl;
            return 0;
        }
    }

    if(s[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 1; i < s.size() - 2; i++) {
        count_ += (s[i] == '_');
        countx += (s[i] == 'X');
    }

    int ans = match("00") + match("25") + match("50") + match("75");

    cout << ans << endl;
}