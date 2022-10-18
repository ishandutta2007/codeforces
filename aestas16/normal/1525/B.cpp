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

const int N = 50;

int n, a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        bool flag = 0;
        fr(n);
        for (int i = 1; i <= n; i++) {
            fr(a[i]);
            if (a[i] < a[i - 1]) flag = 1;
        }
        if (flag == 0) puts("0");
        else if (a[1] == 1 || a[n] == n) puts("1");
        else if (a[n] == 1 && a[1] == n) puts("3");
        else puts("2");
    }
    return 0;
}