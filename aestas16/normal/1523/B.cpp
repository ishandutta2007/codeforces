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

const int N = 1e3;

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr();
        printf("%d\n", n * 3);
        for (int i = 1; i <= n; i += 2) {
            fr(a[i]), fr(a[i + 1]);
            printf("1 %d %d\n", i, i + 1), a[i] = a[i] + a[i + 1];
			printf("2 %d %d\n", i, i + 1), a[i + 1] = a[i + 1] - a[i];
			printf("1 %d %d\n", i, i + 1), a[i] = a[i] + a[i + 1];
			printf("1 %d %d\n", i, i + 1), a[i] = a[i] + a[i + 1];
			printf("2 %d %d\n", i, i + 1), a[i + 1] = a[i + 1] - a[i];
			printf("1 %d %d\n", i, i + 1), a[i] = a[i] + a[i + 1];
        }
    }
    return 0;
}