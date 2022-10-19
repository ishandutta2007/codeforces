#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2, 0);
    vector<int> stat(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] > max(a[i - 1], a[i + 1])) stat[i] = 1, ans += a[i];
        if (a[i] < min(a[i - 1], a[i + 1])) stat[i] = -1, ans -= a[i];
    }

    cout << ans << '\n';
    
    while (q--) {
        int u, v;
        cin >> u >> v;
        set<ii> s;
        for (int i = -1; i <= 1; i++) {
            s.insert({u + i, stat[u + i] * a[u + i]});
            s.insert({v + i, stat[v + i] * a[v + i]});
        }
        swap(a[u], a[v]);
        for (int i = -1; i <= 1; i++) {
            if (u + i > 0 && u + i <= n && a[u + i] > max(a[u + i - 1], a[u + i + 1])) stat[u + i] = 1;
            else if (u + i > 0 && u + i <= n && a[u + i] < min(a[u + i - 1], a[u + i + 1])) stat[u + i] = -1;
            else stat[u + i] = 0;
            if (v + i > 0 && v + i <= n && a[v + i] > max(a[v + i - 1], a[v + i + 1])) stat[v + i] = 1;
            else if (v + i > 0 && v + i <= n && a[v + i] < min(a[v + i - 1], a[v + i + 1])) stat[v + i] = -1;
            else stat[v + i] = 0;
        }
        for (auto e : s) {
            // cout << e.x << ' ' << e.y << ' ' << endl;
            // cout << a[e.x] << ' ' << stat[e.x] << endl;
            ans += a[e.x] * stat[e.x] - e.y;
        }
        cout << ans << '\n';
    }

}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}