#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> A(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        m = max(m, A[i]);
    }
    sort(A.begin(), A.end());

    vector<double> P1(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            double p = (double) 1 / (n * (n - 1) / 2);
            P1[A[i] - A[j]] += p;
        }
    }
    vector<double> P2(m + 1, 0);
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; i + j <= m; ++j) {
            P2[i + j] += P1[i] * P1[j];
        }
    }

    double ans = 0, s = 0;
    for (int i = m; i >= 0; --i) {
        ans += P2[i] * s;
        s += P1[i];
    }

    cout << setprecision(17) << fixed;
    cout << ans << '\n';
}