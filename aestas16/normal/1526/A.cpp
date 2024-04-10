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

int a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    srand(time(0));
    for (int T = fr(); T--;) {
        int n = fr();
        for (int i = 1; i <= n * 2; i++) fr(a[i]);
        for (int t = 1; t <= 1000; t++) {
            for (int i = 2; i <= n * 2; i++) {
                int j = rand() % (i - 1) + 1;
                swap(a[i], a[j]);
            }
            a[0] = a[2 * n], a[2 * n + 1] = a[1];
            for (int i = 1; i <= n * 2; i++)
                if (a[i] * 2 == a[i - 1] + a[i + 1]) goto a;
            for (int i = 1; i <= n * 2; i++)
                printf("%d ", a[i]);
            puts("");
            goto b;
            a:;
        }
        b:;
    }
    return 0;
}