#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
vector<pii> g[maxn];
ll d1[maxn], d2[maxn];
ll ans = 0;
void dfs(int v, int pa) {
    d1[v] = a[v];
    d2[v] = -(1ll<<60);
    for(pair<int, int> c: g[v]) {
        int to = c.first;
        int w = c.second;
        if(to == pa) continue;
        dfs(to, v);
        ll cur = -(1ll<<60);
        if(d1[to] >= w) {
            cur = d1[to] - w + a[v];
        }
        if(cur >= d1[v]) {
            d2[v] = d1[v];
            d1[v] = cur;
        } else {
            d2[v] = max(cur, d2[v]);
        }
    }
}
void dfs2(int v, int pa, ll dis) {
    if(dis < 0) dis = 0;
    ans = max(ans, dis + a[v]);
    ans = max(ans, d1[v]);
    for(pair<int, int> c: g[v]) {
        int to = c.first;
        int w = c.second;
        if(to == pa) continue;
        ll cur = -(1ll<<60);
        if(d1[to] >= w) {
            cur = d1[to] - w + a[v];
        }
        ll z = dis + a[v];
        if(cur == d1[v]) {
            z = max(z, d2[v]);
        } else {
            z = max(z, d1[v]);
        }
        dfs2(to, v, z - w);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        g[x].emplace_back(make_pair(y, c));
        g[y].emplace_back(make_pair(x, c));
    }
    dfs(1, 0);
    dfs2(1, 0, 0ll);
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