#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

int n, a[N];
vector<int> g[N];
vector<int> vv[61];

int solve(int u) {
    vector<bool> check(N, 0);
    vector<int> d(N, 0);
    queue<ii> q;
    int ans = 1e9;
    q.push({u, 0});
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (int e : g[v.x]) {
            if (e == v.y) continue;
            if (d[e]) {
                ans = min(d[v.x] + d[e] + 1, ans);
                continue;
            } 
            if (e != u) {
                q.push({e, v.x});
                d[e] = d[v.x] + 1;
            }
        }
    }
    return ans;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j <= 60; j++) {
            if (bit(a[i], j) == 1) vv[j].pb(i);
        }
    }
    set<ii> s;
    for (int i = 0; i <= 60; i++) {
        if (vv[i].size() > 2) return cout << 3, 0;
        if (vv[i].size() == 2) {
            s.insert({vv[i][0], vv[i][1]});
        }
    }
    for (ii e : s) {
        g[e.x].pb(e.y);
        g[e.y].pb(e.x);
    }
    long long ans = 1e9;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() >= 2) ans = min(ans, solve(i)); 
    }
    if (ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}