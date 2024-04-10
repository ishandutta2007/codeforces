#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2e5, A = 1e7, K = 20, INF = 0x3f3f3f3f;

int a[N + 10], g[N + 5][K + 3], f[N + 5][K + 3], cnt[A + 5];

void work(int &x) {
    for (int i = 2; i * i <= x; i++)
        while (x % (i * i) == 0) x /= (i * i);
}

struct OI {
    int RP, score;
} NOIP2021, FJOI2022;

signed main() {
    NOIP2021.RP++, NOIP2021.score++, FJOI2022.RP++, FJOI2022.score++;
    for (int _ = fr(); _--;) {
        int n = fr(), m = fr(), ans = INF;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) f[i][j] = INF;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), work(a[i]);
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) cnt[a[j]] = 0;
            for (int r = 1, l = 1, tot = 0; r <= n; r++) {
                cnt[a[r]]++, tot += (cnt[a[r]] >= 2);
                while (tot > i) tot -= (cnt[a[l]] >= 2), cnt[a[l]]--, l++;
                g[r][i] = l;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int k = 0; k <= j; k++) f[i][j] = min(f[i][j], f[g[i][k] - 1][j - k] + 1);
        for (int i = 0; i <= m; i++) ans = min(ans, f[n][i]);
        printf("%d\n", f[n][m]);
    }
    return 0;
}