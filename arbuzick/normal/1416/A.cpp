#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> d(n+1, -1), pr(n+1, -1);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i) {
            d[a[i]] = max(d[a[i]], i-pr[a[i]]);
            pr[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i)
            if (d[i] != -1)
                d[i] = max(d[i], n-pr[i]);
        vector<int> ans(n, -1);
        for (int i = n; i > 0; --i) {
            if (d[i] == -1)
                continue;
            ans[d[i]-1] = i;
        }
        for (int i = 1; i < n; ++i) {
            if (ans[i] == -1 && ans[i-1] != -1)
                ans[i] = ans[i-1];
            if (ans[i-1] != -1)
                ans[i] = min(ans[i], ans[i-1]);
        }
        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}