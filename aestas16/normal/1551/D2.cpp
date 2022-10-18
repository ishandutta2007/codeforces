// 392699

#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e2;

int n, m;
char str[N + 10][N + 10];

void solve(int a, int b, int k) {
    if (k < (a >> 1)) return puts("NO"), void();
    k -= (a >> 1);
    if (k & 1) return puts("NO"), void();
    if (a == m) {
        for (int i = 1; i <= m; i++) str[1][i] = (((i + 1) >> 1) & 1) ? 'z' : 'y';
        for (int i = 2; i <= n; i += 2)
            for (int j = 1; j <= m; j += 2) {
                int ii = (i + 1) >> 1, jj = (j + 1) >> 1;
                int val = (ii & 1) << 1 | (jj & 1);
                if (k) {
                    k -= 2;
                    str[i][j] = str[i][j + 1] = 'a' + val, str[i + 1][j] = str[i + 1][j + 1] = 'e' + val;
                } else {
                    str[i][j] = str[i + 1][j] = 'i' + val, str[i][j + 1] = str[i + 1][j + 1] = 'm' + val;
                }
            }
    }
    else {
        for (int i = 1; i <= n; i++) str[i][1] = (((i + 1) >> 1) & 1) ? 'z' : 'y';
        for (int i = 1; i <= n; i += 2)
            for (int j = 2; j <= m; j += 2) {
                int ii = (i + 1) >> 1, jj = (j + 1) >> 1;
                int val = (ii & 1) << 1 | (jj & 1);
                if (k) {
                    k -= 2;
                    str[i][j] = str[i + 1][j] = 'a' + val, str[i][j + 1] = str[i + 1][j + 1] = 'e' + val;
                } else {
                    str[i][j] = str[i][j + 1] = 'i' + val, str[i + 1][j] = str[i + 1][j + 1] = 'm' + val;
                }
            }
    }
    
    puts("YES");
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++) putchar(str[i][j]);
}

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        fr(n), fr(m);
        int k = fr();
        if (n & 1) solve(m, n, k);
        else if (m & 1) solve(n, m, n * m / 2 - k);
        else {
            if (k & 1) {
                puts("NO");
                goto cat;
            }
            puts("YES");
            for (int i = 1; i <= n; i += 2)
                for (int j = 1; j <= m; j += 2) {
                    int ii = (i + 1) >> 1, jj = (j + 1) >> 1;
                    int val = (ii & 1) << 1 | (jj & 1);
                    if (k) {
                        k -= 2;
                        str[i][j] = str[i][j + 1] = 'a' + val;
                        str[i + 1][j] = str[i + 1][j + 1] = 'e' + val;
                    } else {
                        str[i][j] = str[i + 1][j] = 'i' + val;
                        str[i][j + 1] = str[i + 1][j + 1] = 'm' + val;
                    }
                }
            for (int i = 1; i <= n; i++, puts(""))
                for (int j = 1; j <= m; j++) putchar(str[i][j]);
        }
        cat:;
    }
    return 0;
}