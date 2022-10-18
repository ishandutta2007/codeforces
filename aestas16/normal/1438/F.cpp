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

const int H = 18;

int n, h, s1, s2, cnt[(1 << H) + 10];
mt19937 rnd(999392699);

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    fr(h), n = (1 << h) - 1;
    for (int i = 1; i <= 420; i++) {
        int x = rnd() % n + 1, y = rnd() % n + 1, z = rnd() % n + 1;
        while (x == y || y == z || x == z) x = rnd() % n + 1, y = rnd() % n + 1, z = rnd() % n + 1;
        printf("? %d %d %d\n", x, y, z), fflush(stdout), cnt[fr()]++;
    }
    for (int i = 1; i <= n; i++)
        if (cnt[i] > cnt[s1]) s2 = s1, s1 = i;
        else if (cnt[i] > cnt[s2]) s2 = i;
    for (int i = 1; i <= n; i++)
        if (i != s1 && i != s2) {
            printf("? %d %d %d\n", i, s1, s2), fflush(stdout);
            if (i == fr()) return printf("! %d\n", i), fflush(stdout), 0;
        }
    return 0;
}