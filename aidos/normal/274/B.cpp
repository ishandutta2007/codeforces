#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
vector<int> g[maxn];
ll ans = 0;
pair<ll, ll> dfs(int v, int pa) {
    ll mx = 0;
    ll mi = 0;
    for(int to: g[v]) {
        if(to==pa) continue;
        pair<ll, ll> cur = dfs(to, v);
        mx = max(cur.first, mx);
        mi = max(cur.second, mi);
        ans -= cur.first;
        ans -= cur.second;
    }
    ll s = a[v] + mx - mi;
    if(s < 0) {
        mx += -s;
    } else {
        mi += s;
    }
    ans += mx + mi;
    return make_pair(mx, mi);
}
void solve(){
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}