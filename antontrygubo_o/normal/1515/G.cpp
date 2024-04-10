#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

typedef tree<
        int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;

#define mp make_pair


int MOD =  1e9 + 7;



int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}

int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}

int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, MOD-2);
}


mt19937 rnd(time(0));

/*
const int LIM = 1000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C(int n, int k)
{
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/


/*struct DSU
{
    vector<int> sz;
    vector<int> parent;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

int n, m;
vector<vector<pair<int, int>>> G;

vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

set<int> comp;
vector<ll> ans;
vector<ll> d;

void dfs_dist(int v)
{
    for (auto it: G[v]) if (comp.count(it.first) && d[it.first]==-1)
    {
        d[it.first] = d[v] + it.second;
        dfs_dist(it.first);
    }
}

void solve()
{
    int st = *(comp.begin());
    d[st] = 0;
    dfs_dist(st);

    ll g = 0;
    for (auto v: comp) for (auto it: G[v]) if (comp.count(it.first))
    {
        g = __gcd(g, abs(d[v]+it.second-d[it.first]));
    }
    for (auto it: comp) ans[it] = g;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m;
    G.resize(n);

    g.resize(n); gr.resize(n);

    d = vector<ll>(n, -1);

    while (m--)
    {
        int a, b, l; cin>>a>>b>>l; a--; b--;
        G[a].push_back(mp(b, l));

        g[a].push_back (b);
        gr[b].push_back (a);

    }

    ans.resize(n);

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            comp.clear();
            for (auto it: component) comp.insert(it);

            solve();

            component.clear();
        }
    }



    /*for (auto it: ans) cout<<it<<' ';
    cout<<endl;*/

    int q; cin>>q;
    for (int i = 0; i<q; i++)
    {
        ll v, s, t; cin>>v>>s>>t;
        v--;
        if (ans[v]==0)
        {
            if (s==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        }
        else
        {
            if ((s%(__gcd(ans[v], t)))==0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
        }
    }


}