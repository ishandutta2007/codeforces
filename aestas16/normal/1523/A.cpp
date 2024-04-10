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

const int N = 2e3;

char s[N + 10];
map<string, bool> vis;
string tmp;

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr();
        scanf("%s", s + 1);
        vis.clear();
        while (m--) {
            if (vis.count(string(s + 1))) break;
            else vis[string(s + 1)] = 1;
            char tmp = s[1];
            int flag = 1;
            for (int i = 2; i <= n; i++)
                if (s[i] != tmp) {
                    flag = 0;
                    break;
                }
            if (flag) break;
            for (int i = 1; i <= n; i++)
                if (s[i] != '1' && (((s[i - 1] == '1') + (s[i + 1] == '1')) == 1)) s[i] = '2';
            for (int i = 1; i <= n; i++)
                if (s[i] == '2') s[i] = '1';
        }
        puts(s + 1);
    }
    return 0;
}