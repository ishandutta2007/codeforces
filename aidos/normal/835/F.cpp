#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
vector<pii> g[maxn];
vector<pii> cycle;
int u[maxn];
int p[maxn];
int cost[maxn];
int used[maxn];
void dfs(int v, int pa) {
    u[v] = 1;
    for(auto x: g[v]) {
        if(x.first == pa) continue;
        if(u[x.first] == 0) {
            p[x.first] = v;
            cost[x.first] = x.second;
            dfs(x.first, v);
        } else if(u[x.first] == 1) {
            int cur = v;
            while(cur != x.first) {
                cycle.emplace_back(make_pair(p[cur], cost[cur]));
                cur = p[cur];
            }
            cycle.emplace_back(make_pair(v, x.second));
        }
    }
    u[v] = 2;
}
ll a[maxn];
ll b[maxn];
ll mx;
ll dfs2(int v, int pa) {
    ll d = 0;
    for(auto x: g[v]) {
        if(x.first == pa) continue;
        if(used[x.first]) continue;
        ll dis = dfs2(x.first, v) + x.second;
        mx = max(mx, d + dis);
        d = max(d, dis);
    }
    return d;
}
struct node{
    ll max_sum, max_pref, max_suf, sum_edge;
} t[maxn * 4];
node merge(node a, node b, ll e) {
    node c;
    c.max_pref = max(a.max_pref, b.max_pref + e + a.sum_edge);
    c.max_suf = max(b.max_suf, a.max_suf + e + b.sum_edge);
    c.sum_edge = a.sum_edge + b.sum_edge + e;
    c.max_sum = max(max(a.max_sum, b.max_sum), a.max_suf + b.max_pref + e);
    return c;
}
void build(int v , int l, int r) {
    if(l == r) {
        t[v].max_suf = a[l];
        t[v].max_pref = a[l];
        t[v].max_sum = a[l];
        t[v].sum_edge = 0;
        return;
    }
    int  mid = (l + r)/2;

    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    t[v] = merge(t[v*2], t[v*2+1], b[mid + 1]);
}
node get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    if(r <= mid) return get(v * 2, tl, mid, l, r);
    if(l > mid) return get(v * 2 + 1, mid + 1, tr, l, r);
    return merge(get(v * 2, tl, mid, l, r), get(v * 2 + 1, mid + 1, tr, l, r), b[mid + 1]);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].emplace_back(make_pair(y, w));
        g[y].emplace_back(make_pair(x, w));
    }
    dfs(1, 0);
    for(int i = 0; i < cycle.size(); i++) {
        used[cycle[i].first] = 1;
    }
    int len = cycle.size();
    for(int i = 0; i < len; i++) {
        a[i] = dfs2(cycle[i].first, 0);
        b[i] = cycle[i].second;
    }
    for(int i = 0; i < len; i++) {
        //cout << cycle[i].first << " "<< cycle[i].second << " " << a[i] << "\n";
    }
    for(int i = len; i < len * 2; i++) {
        a[i] = a[i-len];
        b[i] = b[i-len];
    }
    build(1, 0, 2 * len - 1);
    ll ans = 1ll<<60;
    for(int i = 0; i < len; i++) {
        ll cur = max(mx, get(1, 0, 2 * len - 1, i, i + len - 1).max_sum);
        ans = min(ans, cur);
    }
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