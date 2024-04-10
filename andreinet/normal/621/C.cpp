#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 100005;

double pr[NMAX];
double dp1[NMAX], dp2[NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pr[i] = (double) (y / p - (x - 1) / p) / (y - x + 1);
    }
    pr[n] = pr[0];

    double ans = 0;

    dp1[0] = 0;
    dp2[0] = 0;
    pr[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp1[i] = dp1[i - 1] * (1 - pr[i - 1]) + (dp2[i - 1] + 1) * pr[i - 1];
        dp2[i] = (dp1[i - 1] + 1) * (1 - pr[i - 1]) + (dp2[i - 1] + 1) * pr[i - 1];
    }

    ans += (dp1[n - 1] * (1 - pr[n - 1]) +
           (dp2[n - 1] + 1) * pr[n - 1]) * (1 - pr[n]);

    dp1[0] = 0;
    dp2[0] = 1;
    pr[0] = 1;
    for (int i = 0; i < n; ++i) {
        dp1[i] = dp1[i - 1] * (1 - pr[i - 1]) + (dp2[i - 1] + 1) * pr[i - 1];
        dp2[i] = (dp1[i - 1] + 1) * (1 - pr[i - 1]) + (dp2[i - 1] + 1) * pr[i - 1];
    }

    ans += (dp1[n - 1] * (1 - pr[n - 1]) +
            dp2[n - 1] * pr[n - 1]) * pr[n];

    cout << setprecision(17) << fixed;
    cout << ans * 2000 << '\n';

}