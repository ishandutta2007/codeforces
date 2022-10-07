#include <bits/stdc++.h>

int A, B, C;
int a[205], b[205], c[205];
long long f[205][205][205];

void solve() {
    scanf("%d%d%d", &A, &B, &C);
    for (int i = 1; i <= A; ++i) {
        scanf("%d", a + i);
    }
    std::sort(a + 1, a + 1 + A);
    for (int i = 1; i <= B; ++i) {
        scanf("%d", b + i);
    }
    std::sort(b + 1, b + 1 + B);
    for (int i = 1; i <= C; ++i) {
        scanf("%d", c + i);
    }
    std::sort(c + 1, c + 1 + C);
    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            for (int k = 0; k <= C; ++k) {
                f[i][j][k] = 0;
                if (i && j) {
                    f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][k] + 1ll * a[i] * b[j]);
                }
                if (i && k) {
                    f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k - 1] + 1ll * a[i] * c[k]);
                }
                if (j && k) {
                    f[i][j][k] = std::max(f[i][j][k], f[i][j - 1][k - 1] + 1ll * b[j] * c[k]);
                }
            }
        }
    }
    printf("%lld\n", f[A][B][C]);
}

int main() {
    int T = 1;
    // scanf("%d", &T);
    while (T--) {
        solve();
    }
}