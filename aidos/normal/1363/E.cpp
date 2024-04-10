#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)998244353 ;
long long ans = 0;
int n;
vector<int> g[maxn];
long long a[maxn];
int b[maxn], c[maxn];
pair<int, int> dfs(int v, int p, long long mi) {
    mi = min(mi, a[v]);
    pair<int, int> cur = make_pair(0, 0);
    if(b[v] != c[v]) {
        if(b[v]) cur.first++;
        else cur.second++;
    }
    for(int to: g[v]) {
        if(to != p) {
            pair<int, int> c = dfs(to, v, mi);
            cur.first += c.first;
            cur.second += c.second;
        }
    }
    int t = min(cur.first, cur.second);
    ans += mi * t*2;
    return make_pair(cur.first - t, cur.second - t);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pair<int, int> d = dfs(1, -1, 1e18);
    if(d.first || d.second) ans = -1;
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}