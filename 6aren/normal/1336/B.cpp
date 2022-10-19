#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve(vector<int> &a, vector<int> &b, vector<int> &c, int &ans) {
    for (int e : a) {
        int k = upper_bound(all(b), e) - b.begin() - 1;
        int kk = lower_bound(all(c), e) - c.begin();
        if (k < 0 || kk == c.size()) continue;
        int u = b[k];
        int v = c[kk];
        // cout << e << ' ' << u << ' ' << v << endl;
        ans = min(ans, (e - u) * (e - u) + (u - v) * (u - v) + (e - v) * (e - v));
    }
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        vector<int> r, g, b;
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        for (int i = 1; i <= nr; i++) {
            int u;
            cin >> u;
            r.pb(u);
        }
        for (int i = 1; i <= ng; i++) {
            int u;
            cin >> u;
            g.pb(u);
        }
        for (int i = 1; i <= nb; i++) {
            int u;
            cin >> u;
            b.pb(u);
        }
        sort(all(r));
        sort(all(g));
        sort(all(b));
        long long ans = 5e18;
        solve(r, g, b, ans);
        solve(r, b, g, ans);
        solve(g, r, b, ans);
        solve(g, b, r, ans);
        solve(b, g, r, ans);
        solve(b, r, g, ans);
        cout << ans << '\n';
    }
    return 0;
}