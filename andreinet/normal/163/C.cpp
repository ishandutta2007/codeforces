#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
typedef long long int lint;

using namespace std;

const double EPS = 1e-9;

int main() {
#ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, v1, v2;
    cin >> n >> l >> v1 >> v2;
    vector<double> A(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    double time = (double) l / (v1 + v2);
    double dist = v2 * time;
    vector<double> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        A[n + i] = A[i] + 2 * l;
    }
    A.push_back(1e12);
    int left = 0, right = 0;
    while (right + 1 < SZ(A) && A[right + 1] - A[left] < dist) {
        ++right;
    }
    int type = 0;
    while (left < n) {
        double posLeft, posRight;
        if (type == 0) {
            posLeft = A[left];
            posRight = A[left] + dist;
        } else {
            posRight = A[right];
            posLeft = A[right] - dist;
        }
        double distNext1 = A[left + 1] - posLeft;
        double distNext2 = A[right + 1] - posRight;
        if (distNext1 < distNext2) {
            dp[right - left] += distNext1 / (2.0 * l);
            type = 0;
            left++;
        } else {
            dp[right - left] += distNext2 / (2.0 * l);
            type = 1;
            right++;
        }
    }
    cout << setprecision(20) << fixed;
    double p0 = 1;
    for (int i = 1; i <= n; ++i) {
        p0 -= dp[i];
    }
    //cout << p0 << '\n';
    for (int i = 0; i <= n; ++i) {
        cout << dp[i] << '\n';
    }
}