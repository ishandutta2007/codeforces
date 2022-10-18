#include <bits/stdc++.h>

#define int int64_t
#define double long double
using namespace std;
const double eps = 1e-5, inf = 1e15;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y) {
        return a[x] > a[y];
    });
    double l = 0, r = 1e9;
    for(int z = 0; z < 200; z++) {
        double m = (l + r) / 2;
        double ta[n];
        for(int i = 0; i < n; i++) {
            ta[i] = a[i] - m * b[i];
        }
        double dp[n + 1];
        fill(dp, dp + n + 1, inf);
        dp[0] = 0;
        double tdp[n + 1];
        fill(tdp, tdp + n + 1, inf);
        tdp[0] = 0;
        int cur = 0;
        for(int i = 0; i < n; i++) {
            double ndp[n + 1];
            fill(ndp, ndp + n + 1, inf);
            for(int j = 0; j <= cur; j++) {
                    ndp[j] = min(ndp[j], tdp[j] + ta[p[i]]);
                    ndp[j + 1] = min(ndp[j + 1], tdp[j]);
            }
            copy(ndp, ndp + n + 1, tdp);
            cur++;
            if(i + 1 == n || a[p[i]] != a[p[i + 1]]) {
                double ndp[n + 1];
                fill(ndp, ndp + n + 1, inf);
                for(int i = 0; i <= n; i++) {
                    for(int j = 0; j <= min(i, cur); j++) {
                        ndp[i - j + (cur - j)] = min(ndp[i - j + (cur - j)],
                                                     dp[i] + tdp[j]);
                    }
                }
                copy(ndp, ndp + n + 1, dp);
                fill(tdp, tdp + n + 1, inf);
                tdp[0] = 0;
                cur = 0;
            }
        }
        double mn = *min_element(dp, dp + n + 1);
        if(mn <= 0) {
            r = m;
        } else {
            l = m;
        }
    }
    double ans = l * 1000;
    int ansi;
    if(abs(ans - llround(ans)) < eps) {
        ansi = llround(ans);
    } else {
        ansi = llround(ceil(ans));
    }
    cout << ansi << endl;
}