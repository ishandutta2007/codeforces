#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int INF = 0x3f3f3f3f;

int solve(int h, int w, int a, int b,
          const vector<int>& A) {
    int n = SZ(A);
    int v = max(a, b);
    vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
    vector<vector<int>> ndp(n + 1, vector<int>(v + 1, 0));
    h = min(h, v);
    w = min(w, v);
    dp[0][h] = w;
    for (int i = 0; i < n; ++i) {
        for (auto& p: ndp) {
            fill(p.begin(), p.end(), 0);
        }
        for (int k = 0; k < i + 1; ++k) {
            for (int j = 0; j <= v; ++j) {
                ndp[k][j] = dp[k][j];
            }
        }
        for (int k = 0; k < i + 1; ++k) {
            for (int h = 1; h <= v; ++h) {
                int nval = min((int64_t) v,
                        (int64_t) h * A[i]);
                ndp[k + 1][nval] = max(ndp[k + 1][nval], dp[k][h]);
                nval = min((int64_t) v,
                        (int64_t) dp[k][h] * A[i]);
                ndp[k + 1][h] = max(ndp[k + 1][h], nval);
            }
        }
        dp.swap(ndp);
    }
    int ans = INF;
    for (int i = 0; i <= n; ++i) {
        for (int j = v - 1; j >= 0; --j) {
            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        }
        if (dp[i][a] >= b || dp[i][b] >= a) {
            ans = i;
            break;
        }
    }
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> A(n);
    for (int& p: A) {
        cin >> p;
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    if (SZ(A) > 34) {
        A.resize(34);
    }
    int ans = solve(h, w, a, b, A);
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
}