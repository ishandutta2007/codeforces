#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
const ll inf = 2e18;
int n, m;
int a[maxn], b[maxn];
const int mod = 998244353;
int k;
vector<int> g[maxn], G[maxn];
int tin[maxn];
int tout[maxn];
int timer;
int p[maxn];
int L[maxn];
int R[maxn];
int d[maxn];
int bad[maxn];

void dfs(int v, int pa) {
    tin[v] = ++timer;
    p[v] = pa;
    for(int to: g[v]) {
        if(to != pa) dfs(to, v);
    }
    tout[v] = timer;
}
int get(int v) {
    if(d[v] == v) return v;
    return d[v] = get(d[v]);
}
void merge(int u, int v) {
    u = get(u);
    v = get(v);
    if(u != v) {
        d[u] = v;
    }
}
int dp[maxn][2];
ll ans = 0;
bool dfs2(int v, int pa) {
    vector<int> s;
    for(int to: G[v]) {
        if(to == pa) continue;
        if(dfs2(to, v)) {
            ans++;
            s.push_back(to);
        }
    }
    if(!bad[v]) {
        if(s.size() == 0) return 0;
        return 1;
    } else {
        return 1;
    }
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = i;
        L[i] = maxn;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int st = 1;
    while(a[st] == 0) ++st;
    dfs(st, -1);
    for(int i = 1; i <= n; i++) {
        L[a[i]] = min(L[a[i]], tin[i]);
        R[a[i]] = max(R[a[i]], tin[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) continue;
        bad[get(i)] = 1;
        int c = a[i];
        int v = i;
        while(L[c] < tin[v] || tout[v] < R[c]) {
            if(a[p[v]] != 0) {
                merge(p[v], v);
                if(a[p[v]] != c) {
                    cout << 0 << "\n";
                    return;
                }
                break;
            } else {
                merge(p[v], v);
                bad[get(v)]=1;
                v = p[v];
                a[v] = c;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        //cout << get(i) << " ";
    }
    //cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int to: g[i]) {
            if(get(to) != get(i)) {
                G[get(to)].push_back(get(i));
                //G[get(i)].push_back(get(to));
            }
        }
    }
    dfs2(get(st), -1);
    cout << ans << "\n";
}
int main () {
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}