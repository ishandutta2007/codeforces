#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 209;
ll dp[MxN + 9][MxN + 9][MxN + 9];
int a[MxN + 9], b[MxN + 9], c[MxN + 9];

void f() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < m; ++j)
        cin >> b[j];
    for (int k = 0; k < p; ++k)
        cin >> c[k];

    sort(a, a + n);
    sort(b, b + m);
    sort(c, c + p);

    for (int i = n; i >= 0; --i)
        for (int j = m; j >= 0; --j)
            for (int k = p; k >= 0; --k) {
                ll &res = dp[i][j][k] = 0;
                if (i < n)
                    res = max(res, dp[i + 1][j][k]);
                if (j < m)
                    res = max(res, dp[i][j + 1][k]);
                if (k < p)
                    res = max(res, dp[i][j][k + 1]);
                if (i < n && j < m)
                    res = max(res, a[i] * b[j] + dp[i + 1][j + 1][k]);
                if (i < n && k < p)
                    res = max(res, a[i] * c[k] + dp[i + 1][j][k+1]);
                if (j < m && k < p)
                    res = max(res, b[j] * c[k] + dp[i][j + 1][k + 1]);
            }

    cout << dp[0][0][0] << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    f();
    return 0;
}