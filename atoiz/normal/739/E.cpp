#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <cassert>

using namespace std;

const int N = 2007;
int n, a, b, trace_a[N], trace_b[N];
double p[N], u[N], dp[N], ans;

bool check_a(double k_a, double k_b)
{
    dp[0] = trace_a[0] = trace_b[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1], trace_a[i] = trace_a[i - 1], trace_b[i] = trace_b[i - 1];

        if (dp[i - 1] + p[i] + k_a > dp[i]) {
            dp[i] = dp[i - 1] + p[i] + k_a;
            trace_a[i] = trace_a[i - 1] + 1;
            trace_b[i] = trace_b[i - 1];
        }
        if (dp[i - 1] + u[i] + k_b > dp[i]) {
            dp[i] = dp[i - 1] + u[i] + k_b;
            trace_a[i] = trace_a[i - 1];
            trace_b[i] = trace_b[i - 1] + 1;
        }
        if (dp[i - 1] + p[i] + u[i] - p[i] * u[i] + k_a + k_b > dp[i]) {
            dp[i] = dp[i - 1] + p[i] + u[i] - p[i] * u[i] + k_a + k_b;
            trace_a[i] = trace_a[i - 1] + 1;
            trace_b[i] = trace_b[i - 1] + 1;
        }
    }
    ans = dp[n] - k_a * a - k_b * b;
    // cout << k_a << ' ' << k_b << ": " << trace_a[n] << ' ' << trace_b[n] << ": " << ans << endl;
    return trace_a[n] <= a;
}

bool check_b(double k_b)
{
    double lo = -1, hi = 0;
    for (int trial = 0; trial < 50; ++trial) {
        double mid = (lo + hi) / 2;
        if (check_a(mid, k_b)) lo = mid;
        else hi = mid;
    }
    check_a(lo - 1e-9, k_b);
    assert(trace_a[n] <= a);
    return trace_b[n] <= b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> u[i];

    double lo = -1, hi = 0;
    for (int trial = 0; trial < 50; ++trial) {
        // cout << lo << ' ' << hi << endl;
        double mid = (lo + hi) / 2;
        if (check_b(mid)) lo = mid;
        else hi = mid;
    }
    check_b(lo - 1e-9);
    // cerr << trace[n][a] << endl;
    cout << fixed << setprecision(6) << ans;
}