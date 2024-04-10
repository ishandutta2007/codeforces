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

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), Max = -101, flag = 0;
        for (int i = 1, a; i <= n; i++) {
            fr(a), Max = max(Max, a);
            if (a < 0) flag = 1;
        }
        if (flag) puts("NO");
        else {
            puts("YES");
            printf("%d\n", Max + 1);
            for (int i = 0; i <= Max; i++) printf("%d ", i);
            puts("");
        }
    }
    return 0;
}