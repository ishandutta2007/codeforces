/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 5e5;

int n, k;
char str[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(n), fr(k), scanf("%s", str + 1);
    for (int i = 2, j; i <= n; i++) {
        if (str[i] > str[1]) {
            n = i - 1;
            break;
        }
        if (str[i] == str[1]) {
            for (j = 1; j < i - 1 && j + i <= n && str[j + 1] == str[i + j]; j++) ;
            if (j + i == n + 1) {
                n = i - 1;
                break;
            }
            if (j == i - 1) continue;
            if (str[j + i] > str[j + 1]) {
                n = i - 1;
                break;
            }
        }
    }
    str[n + 1] = 0;
    for (int i = 1; i <= k / n; ++i) printf("%s", str + 1);
    for (int i = 1; i <= k % n; ++i) putchar(str[i]);
    return puts(""), 0;
}
/*
dacbdbacbd
*/