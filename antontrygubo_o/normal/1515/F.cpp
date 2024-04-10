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
};


ll n, m, x;

vector<vector<pair<int, int>>> G;

vector<ll> a;

vector<ll> sz, sum;

void dfs(int v, int par = -1)
{
    for (auto it: G[v]) if (it.first!=par)
    {
        dfs(it.first, v);
        sz[v]+=sz[it.first];
        sum[v]+=sum[it.first];
    }
    sz[v]++; sum[v]+=a[v];
}

void output(int v, int par = -1)
{
    vector<pair<ll, pair<int, int>>> diff;
    for (auto it: G[v]) if (it.first!=par)
    {
        diff.push_back(mp(sum[it.first]-(sz[it.first]-1)*x, it));
    }

    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());

    for (auto it: diff)
    {

        if (a[v] + a[it.second.first]>=x)
        {
            cout<<it.second.second<<endl;
            a[it.second.first] = a[v] + a[it.second.first] - x;
            output(it.second.first, v);
            a[v] = a[it.second.first];
        }
        else
        {
            output(it.second.first, v);
            cout<<it.second.second<<endl;
            a[v] = a[v] + a[it.second.first] - x;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n>>m>>x;

    G.resize(n);

    a.resize(n); for (int i = 0; i<n; i++) cin>>a[i];

    ll S = 0; for (auto it: a) S+=it;
    if (S<x*(n-1)) {cout<<"NO"<<endl; return 0;}

    cout<<"YES"<<endl;

    DSU dsu(n);
    for (int i = 0; i<m; i++)
    {
        int u, v; cin>>u>>v; u--; v--;

        if (dsu.find_set(u)!=dsu.find_set(v))
        {
            dsu.union_sets(u, v);
            G[u].push_back(mp(v, i+1)); G[v].push_back(mp(u, i+1));
        }
    }

    sz.resize(n); sum.resize(n);

    dfs(0);
    output(0);


}

/*
5 4 1
0 0 0 0 4
1 2
1 3
1 4
1 5

 */