#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int) 2e5 + 10;
const int mod = 998244353;
const int inf = (1 << 30) - 1;
const double pi = acos(-1);
const double eps = 1e-15;
int n, m;
pair < int, pii > e[maxn];
ll ans[maxn];
int p[maxn];
int sz[maxn];
int get(int v) {
    if(v == p[v]) return v;
    return p[v] = get(p[v]);
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n-1; i++) {
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    }
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    sort(e, e + n - 1);
    for(int i = 0; i < n-1; i++) {
        int u = e[i].second.first;
        int v = e[i].second.second;
        int w = e[i].first;
        int pu = get(u);
        int pv = get(v);
        ans[w] += sz[pu] * 1ll * sz[pv];
        p[pu] = pv;
        sz[pv] += sz[pu];
    }
    for(int i = 1; i < maxn; i++) ans[i] += ans[i-1];
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}