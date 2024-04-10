/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

int n;
string s;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        fr(n), cin >> s;
        for (char i = 'a'; i <= 'z'; i++) {
            string str = "";
            str += i;
            if (s.find(str) == s.npos) {
                cout << str << endl;
                goto cat;
            }
        }
        for (char i = 'a'; i <= 'z'; i++) {
            string str = "";
            str += i;
            for (char j = 'a'; j <= 'z'; j++) {
                if (s.find(str + j) == s.npos) {
                    cout << str + j << endl;
                    goto cat;
                }
            }
        }
        for (char i = 'a'; i <= 'z'; i++) {
            string str = "";
            str += i;
            for (char j = 'a'; j <= 'z'; j++) {
                for (char k = 'a'; k <= 'z'; k++) {
                    if (s.find(str + j + k) == s.npos) {
                        cout << str + j + k << endl;
                        goto cat;
                    }
                }
            }
        }
        cat:;
    }
    return 0;
}