#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 20005, INF = 2 * 0x3f3f3f3f;

int X[NMAX], Y[NMAX], P;
int dp1[2][NMAX], dp2[2][NMAX];
int dpc1[NMAX], dpc2[NMAX];

char fans[2 * NMAX];

int solve(int left, int right, int lx, int rx, int ly, int ry) {
    if (left == right) {
        if (lx < rx) {
            fans[left] = 'C';
        } else {
            fans[left] = 'S';
        }
    } else {
        int mid = (left + right) / 2;
        fill(dp1[0] + ly, dp1[0] + ry + 1, -INF);
        fill(dp2[0] + ly, dp2[0] + ry + 1, -INF);
        for (int i = lx, u = 1; i <= rx; ++i, u ^= 1) {
            int ri = rx - (i - lx);

            if (i == lx) {
                dp1[u][ly] = (X[lx] + Y[ly]) % P;
                dp2[u][ry] = 0;
            } else {
                dp1[u][ly] = dp1[u ^ 1][ly] + (X[i] + Y[ly]) % P;
                dp2[u][ry] = dp2[u ^ 1][ry] + (X[ri + 1] + Y[ry]) % P;
            }
            for (int j = ly + 1; j <= ry; ++j) {
                dp1[u][j] = max(dp1[u ^ 1][j], dp1[u][j - 1]) +
                            (X[i] + Y[j]) % P;
            }
            for (int j = ry - 1; j >= ly; --j) {
                dp2[u][j] = max(dp2[u ^ 1][j] + (X[ri + 1] + Y[j]) % P,
                                dp2[u][j + 1] + (X[ri] + Y[j + 1]) % P);
            }

            if (i + ly <= mid && mid - i <= ry) {
                dpc1[i] = dp1[u][mid - i];
            }
            if (ri + ly <= mid && mid - ri <= ry) {
                dpc2[ri] = dp2[u][mid - ri];
            }
        }

        int ans = -INF, p = -1;
        for (int i = lx; i + ly <= mid && i <= rx; ++i) {
            if (!(mid - i <= ry)) continue;
            if (ans < dpc1[i] + dpc2[i]) {
                ans = dpc1[i] + dpc2[i];
                p = i;
            }
        }

        solve(left, mid, lx, p, ly, mid - p);
        solve(mid + 1, right, p, rx, mid - p, ry);

        return ans;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m >> P;
    
    for (int i = 0; i < n; ++i) {
        cin >> X[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> Y[j];
    }
    
    if (n == 1 && m == 1) {
        cout << (X[0] + Y[0]) % P << '\n';
        cout << '\n';
        return 0;
    }

    cout << solve(1, n + m - 2, 0, n - 1, 0, m - 1) << '\n';
    cout << fans + 1 << '\n';
}