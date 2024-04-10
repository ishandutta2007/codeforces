/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define int long long

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

const int N = 3e5, S = 30;

int a[N + 10], c[N + 10], fa[N + 10][31];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

signed main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    int T = fr(), opt, x, y, z; fr(a[0]), fr(c[0]);
    for (int i = 1; i <= T; i++) {
        fr(opt), fr(x), fr(y);
        if (opt == 1) {
            fr(z), fa[i][0] = x, a[i] = y, c[i] = z;
            for (int j = 1; j <= S; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
        } else {
            int cnt = 0, ans = 0, X = x, Y = y;
            while (Y > 0) {
                int u = X;
                for (int i = S; ~i; i--)
                    if (a[fa[u][i]] > 0) u = fa[u][i];
                int tmp = min(a[u], Y);
                a[u] -= tmp, Y -= tmp, ans += tmp * c[u], cnt += tmp;
                if (u == X) break;
            }
            printf("%lld %lld\n", cnt, ans);
        }
        fflush(stdout);
    }
    return 0;
}