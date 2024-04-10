#include <bits/stdc++.h>

#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
using namespace std;

const int maxn = 5005, mod = 1000000007;
int dp[maxn][maxn];
int sum[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> pr(n + 1);
        for (int i = 0; i < n; ++i) {
            pr[i + 1] = pr[i] + a[i];
        }
        vector<int> pr_m(n + 1);
        for (int i = 0; i < n; ++i) {
            pr_m[i + 1] = max(pr_m[i], pr[i + 1]);
        }
        while (m--) {
            int x;
            cin >> x;
            if (pr[n] <= 0 && pr_m[n] < x) {
                cout << -1 << ' ';
            } else if (x <= pr_m[1]) {
                cout << 0 << ' ';
            } else {
                int cnt;
                int l = -1, r = x + 1;
                while (l < r - 1) {
                    int m1 = (l + r) / 2;
                    if (m1 * pr[n] + pr_m[n - 1] >= x) {
                        r = m1;
                    } else {
                        l = m1;
                    }
                }
                cnt = r * n;
                if (pr[n] <= 0) {
                    cnt = 0;
                }
                int val = x - (cnt / n) * pr[n];
                l = -1, r = n;
                while (l < r - 1) {
                    int m1 = (l + r) / 2;
                    if (pr_m[m1] >= val) {
                        r = m1;
                    } else {
                        l = m1;
                    }
                }
                cout << cnt + l << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}