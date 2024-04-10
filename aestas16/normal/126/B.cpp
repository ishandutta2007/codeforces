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

const int N = 2e7;

int n, Max, ans, pos, z[N + 10];
char str[N + 10];

void Z_Algorithm() {
    z[1] = n;
    for (int i = 2, l = 0, r = 0; i <= n; i++) {
        if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] <= n && str[i + z[i]] == str[z[i] + 1]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

struct OI {
    int RP, score;
} FJOI2021;

int main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    scanf("%s", str + 1), n = strlen(str + 1), Z_Algorithm();
    for (int i = 2; i <= n; i++) {
        if (i + z[i] - 1 == n && z[i] <= Max)
            if (ans < z[i]) ans = z[i], pos = i;
        Max = max(Max, z[i]);
    }
    if (ans == 0) return puts("Just a legend"), 0;
    for (int i = pos; i <= pos + ans - 1; i++) putchar(str[i]);
    return puts(""), 0;
}