#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, q;
int a[maxn];
int b[maxn];
int u[maxn];
int c[maxn][2];
int p[maxn];
int sz;
int V[maxn];
int par[maxn];
int get(int v) {
    if(p[v] == v) return v;
    return p[v] = get(p[v]);
}
vector<int> g[maxn];
void merge(int x, int y) {
    int px = get(x);
    int py = get(y);
    if(px == py) return;
    p[sz] = sz;
    p[px] = sz;
    p[py] = sz;

    g[sz].emplace_back(px);
    g[sz].emplace_back(py);
    sz++;
}
int tin[maxn];
int tout[maxn];
int timer = 0;
int S[maxn];
void dfs(int v) {
    S[timer] = v;
    tin[v] = timer++;
    for(int to: g[v]) {
        dfs(to);
    }
    tout[v] = timer-1;
}
pii t[4*maxn];
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = make_pair(V[S[l]], l);
    } else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
pii get_max(int v, int tl, int tr, int l, int r) {
    if(tl > r || l > tr) return make_pair(-1, 0);
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    return max(get_max(v * 2, tl, mid, l, r), get_max(v * 2 + 1, mid + 1, tr, l, r));
}
void update(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        t[v].first = 0;
    } else {
        int mid = (tl + tr)/2;
        if(pos <= mid) update(v * 2, tl, mid, pos);
        else update(v * 2 + 1, mid + 1, tr, pos);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}
void solve() {
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        cin >> V[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> c[i][0] >> c[i][1];
        c[i][1]--;
        if(c[i][0] == 2) {
            u[c[i][1]] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
    sz = n;
    for(int i = 0; i < m; i++) {
        if(u[i]) continue;
        merge(a[i], b[i]);
    }
    for(int i = q-1; i >= 0; i--) {
        if(c[i][0] == 1) {
            par[i] = get(c[i][1]);
        } else {
            merge(a[c[i][1]], b[c[i][1]]);
        }
    }
    for(int i = 0; i < sz; i++) {
        if(get(i) == i) {
            dfs(i);
        }
    }
    build(1, 0, sz-1);
    for(int i = 0; i < q; i++) {
        if(c[i][0] == 1) {
            pii g = get_max(1, 0, sz-1, tin[par[i]], tout[par[i]]);
            cout << g.first << "\n";
            update(1, 0, sz - 1, g.second);

        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}