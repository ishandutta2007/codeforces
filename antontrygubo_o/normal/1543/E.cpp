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

int MOD =  998244353;

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
const int LIM = 100000;

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

/*
struct DSU
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

int n, N;
vector<vector<int>> G;

vector<vector<int>> mapka;

bool check(vector<int> &a, int x)
{
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it==a.end()) return false;
    return ((*it)==x);
}

void dfs(int u, int v, int level)
{
    for (auto u1: G[u]) if (u1!=v)
        for (auto v1: G[v])  if (v1!=u)
            {
                if (check(G[u1], v1))
                {
                    if (mapka[level][u1]==-1)
                    {
                        mapka[level][u1] = v1; mapka[level][v1] = u1;
                        dfs(u1, v1, level);
                    }
                }
            }
}

bool check_deg(int x)
{
    if (x==1) return true;
    if (x%2) return false;
    return check_deg(x/2);
}

void solve()
{
    cin>>n;
    N = (1<<n);
    G.clear(); G.resize(N);
    for (int i = 0; i<n*(1<<(n-1)); i++)
    {
        int u, v; cin>>u>>v; G[u].push_back(v); G[v].push_back(u);
    }
    
    /*for (int bit = 0; bit<n; bit++)
    {
        for (int i = 0; i<N; i++) if (i&(1<<bit))
        {
            int u = i; int v = i^(1<<bit);
            G[u].push_back(v); G[v].push_back(u);
        }
    }*/
    
    for (int i = 0; i<N; i++) sort(G[i].begin(), G[i].end());

    mapka.clear(); mapka = vector<vector<int>>(n, vector<int>(N, -1));
    int cnt = -1;
    for (auto it: G[0])
    {
        cnt++;
        mapka[cnt][0] = it;
        mapka[cnt][it] = 0;
        dfs(0, it, cnt);
    }

    vector<int> ans(N);
    for (int i = 1; i<N; i++)
    {
        int bit = 0;
        while ((i&(1<<bit))==0) bit++;
        int par = i^(1<<bit);
        ans[i] = mapka[bit][ans[par]];
    }

    for (auto it: ans) cout<<it<<' ';
    cout<<endl;

    vector<int> invans(N);
    for (int i = 0; i<N; i++) invans[ans[i]] = i;

    /*for (auto it: ans) cout<<it<<' ';
    cout<<endl;*/

    if (!check_deg(n)) {cout<<-1<<endl; return;}

    for (int i = 0; i<N; i++)
    {
        int color = 0;
        for (int j = 0; j<n; j++) if (invans[i]&(1<<j)) color^=j;
        cout<<color<<' ';
    }
    cout<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();

}