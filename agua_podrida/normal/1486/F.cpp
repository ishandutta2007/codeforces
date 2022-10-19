#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it : s)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
#define sq(a) (a)*(a)
#define teamSize(t) ((t)<t4 ? 4 : ( (t)<t4+t3 ) ? 3 : 2 )
#define R real
#define I imag
const ll mod = 1e9+7;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

int n;
vector<priority_queue<int>> dp;
vector<priority_queue<pi>> dp2;
vi usos;
ll res = 0;

void dfs(vvi& g, int v, int p, int h){
    for(auto u : g[v]){
        if(u == p) continue;
        dfs(g,u,v,h+1);
        if(dp[u].size() > dp[v].size()) swap(dp[u],dp[v]);
        while(!dp[u].empty()) dp[v].push(dp[u].top()), dp[u].pop();
    }
    while(!dp[v].empty() and dp[v].top() > h) dp[v].pop();
    usos[v] = dp[v].size();
}

ll magia(vpi& coso){
    map<int,int> por1;
    map<pi,int> por2;
    int u,v;
    for(auto x : coso){
        tie(u,v) = x;
        if(u > v) swap(u,v);
        por1[u]++;
        por1[v]++;
        por2[{u,v}]++;
    }
    ll tot = coso.size();
    ll res = 0;
    for(auto x : coso){
        tie(u,v) = x;
        if(u > v) swap(u,v);
        res += tot - por1[u] - por1[v] + por2[{u,v}];
    }
    return res/2;
}

ll magia2(vpi& coso, map<int,int>& coso2){
    ll total = 0;
    ll res = 0;
    for(auto x : coso2) total += x.second;
    int u,v;
    for(auto w : coso){
        tie(u,v) = w;
        res += total - coso2[u] - coso2[v];
    }
    return res;
}

void dfs2(vvi& g, int v, int p, int h){
    vpi coso;
    map<int,int> donde;
    for(auto u : g[v]){
        if(u == p) continue;
        dfs2(g,u,v,h+1);
        while(!dp2[u].empty() and dp2[u].top().first == h){
            int w = dp2[u].top().second;
            if(donde.count(w)) {
                coso.pb({u,donde[w]});
                donde.erase(w);
            }
            else donde[w] = u;
            dp2[u].pop();
        }
    }
    int fresco = n;
    while(!dp2[v].empty() and dp2[v].top().first == h){
        int w = dp2[v].top().second;
        coso.pb({fresco,donde[w]});
        donde.erase(w);
        fresco++;
        dp2[v].pop();
    }
    map<int,int> coso2;
    for(auto u : g[v]){
        if(u == p) continue;
        coso2[u] = dp2[u].size();
    }
    coso2[v] = dp2[v].size();

    res += magia(coso);
    res += magia2(coso,coso2);
    for(auto u : g[v]) {
        if (u == p) continue;
        if (dp2[u].size() > dp2[v].size()) swap(dp2[u], dp2[v]);
        while (!dp2[u].empty()) dp2[v].push(dp2[u].top()), dp2[u].pop();
    }
}

void pairs_of_paths(){
    cin>>n;
    vvi g(n);
    int u,v;
    F0(i,n-1){
        cin>>u>>v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int m;
    cin>>m;
    vpi p(m);
    F0(i,m) {
        cin>>u>>v;
        u--; v--;
        p[i] = {u,v};
    }
    LCA l(g);
    dp.resize(n);
    dp2.resize(n);
    usos = vi(n);
    F0(i,m){
        tie(u,v) = p[i];
        if(u == v) continue;
        int w = l.lca(u,v);
        dp[u].push(l.height[w]);
        dp[v].push(l.height[w]);
    }
    dfs(g,0,0,0);
    F0(i,m){
        tie(u,v) = p[i];
        if(u == v) continue;
        int w = l.lca(u,v);
        usos[w]--;
    }
    F0(i,m){
        tie(u,v) = p[i];
        if(u != v) continue;
        res += usos[u];
        usos[u]++;
    }

    F0(i,m){
        tie(u,v) = p[i];
        if(u == v) continue;
        int w = l.lca(u,v);
        int h = l.height[w];
        dp2[u].push({h,i});
        dp2[v].push({h,i});
    }

    dfs2(g,0,0,0);

    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pairs_of_paths();

}