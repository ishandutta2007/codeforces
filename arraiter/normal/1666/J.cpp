#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 210;
int n, ptr[maxn][maxn], ans[maxn];
ll c[maxn][maxn], f[maxn][maxn], g[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &c[i][j]), c[i][j] += c[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                g[i][j] += c[k][i - 1] + c[k][n] - c[k][j];
            }
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            f[l][r] = LLONG_MAX;
            for (int k = l; k <= r; k++) {
                ll s = f[l][k - 1] + f[k + 1][r];
                s += g[l][k - 1] + g[k + 1][r];
                if (s < f[l][r]) f[l][r] = s, ptr[l][r] = k;
            }
        }
    }
    auto rec = [&](auto self, int l, int r, int fa) {
        if (l > r) return;
        int k = ptr[l][r];
        ans[k] = fa;
        self(self, l, k - 1, k), self(self, k + 1, r, k);
    };
    rec(rec, 1, n, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}