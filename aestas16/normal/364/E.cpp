#include <bits/stdc++.h>

#define int long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
    a = f ? -a : a;
}
template <class T, class... Y> void fr(T &t, Y &... a) { fr(t), fr(a...); }
int fr() { int a; return fr(a), a; }

const int N = 2500;

int n, m, k, ans, sum[N + 10][N + 10], f[2][10];
char mp[N + 10][N + 10];

int Sum(int xa, int xb, int ya, int yb) { return sum[xb][yb] - sum[xa][yb] - sum[xb][ya] + sum[xa][ya]; }

void dc(int xa, int xb, int ya, int yb, bool t) {
    if (xa == xb || ya == yb) return;
    if ((xa == xb - 1) && (ya == yb - 1)) return ans += (Sum(xa, xb, ya, yb) == k), void();
    if (t) {
        int mid = (xa + xb) >> 1; dc(xa, mid, ya, yb, 0), dc(mid, xb, ya, yb, 0);
        for (int i = ya; i <= yb; i++) {
            f[0][0] = f[1][0] = mid;
            for (int j = 1; j <= k + 1; j++) f[0][j] = xa, f[1][j] = xb;
            for (int j = i + 1; j <= yb; j++) {
                for (int p = 1; p <= k + 1; p++)
                    while (Sum(f[0][p], mid, i, j) >= p) f[0][p]++;
                for (int p = 1; p <= k + 1; p++)
                    while (Sum(mid, f[1][p], i, j) >= p) f[1][p]--;
                for (int p = 0; p <= k; p++) ans += (f[0][p] - f[0][p + 1]) * (f[1][k - p + 1] - f[1][k - p]);
            }
        }
    } else {
        int mid = (ya + yb) >> 1; dc(xa, xb, ya, mid, 1), dc(xa, xb, mid, yb, 1);
        for (int i = xa; i <= xb; i++) {
            f[0][0] = f[1][0] = mid;
            for (int j = 1; j <= k + 1; j++) f[0][j] = ya, f[1][j] = yb;
            for (int j = i + 1; j <= xb; j++) {
                for (int p = 1; p <= k + 1; p++)
                    while (Sum(i, j, f[0][p], mid) >= p) f[0][p]++;
                for (int p = 1; p <= k + 1; p++)
                    while (Sum(i, j, mid, f[1][p]) >= p) f[1][p]--;
                for (int p = 0; p <= k; p++) ans += (f[0][p] - f[0][p + 1]) * (f[1][k - p + 1] - f[1][k - p]);
            }
        }
    }
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n, m, k);
    for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (mp[i][j] - '0');
    dc(0, n, 0, m, 0), printf("%lld\n", ans);
    return 0;
}