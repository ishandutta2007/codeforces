#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

double sqDist(const pair<int, int>& a, const pair<int, int>& b) {
    return (double) (a.first - b.first) * (a.first - b.first) +
           (double) (a.second - b.second) * (a.second - b.second);
}
double dist(const pair<int, int>& a, const pair<int, int>& b) {
    return sqrt(sqDist(a, b));
}

double dp[100005][4];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    pair<int, int> X[2];
    X[0] = make_pair(ax, ay);
    X[1] = make_pair(bx, by);

    dp[0][1] = dp[0][2] = dp[0][3] = 1e99;
    for (int i = 1; i <= n; ++i) {
        double d = 2 * dist(A[i - 1], make_pair(tx, ty));
        for (int j = 0; j < 4; ++j) {
            dp[i][j] = 1e99;
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
            for (int k = 0; k < 2; ++k) {
                if (j & (1 << k)) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j ^ (1 << k)] +
                                   dist(X[k], A[i - 1]) + d / 2);
                }
            }
        }
    }
    double ans = min({dp[n][1], dp[n][2], dp[n][3]});

    cout << setprecision(11) << fixed;
    cout << ans << '\n';
}