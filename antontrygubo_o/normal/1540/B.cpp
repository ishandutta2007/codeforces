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


const int MOD =  1e9 + 7;



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
const int LIM = 200000;

vector<int> facs(LIM), invfacs(LIM);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<LIM; i++) facs[i] = mul(facs[i-1], i);
    invfacs[LIM-1] = inv(facs[LIM-1]);
    for (int i = LIM-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
}

int C1(int n, int k)
{
    return mul(invfacs[n], mul(facs[k], facs[n-k]));
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

vector<vector<int>> dp;
vector<vector<int>> G;

int inv2 = inv(2);

int ans = 0;

int n;
vector<int> d;

vector<vector<int>> subtrees;

void dfs1(int v, int par = -1)
{
    vector<vector<int>> G1;

    subtrees[v].push_back(v);

    for (auto it: G[v]) if (it!=par)
    {
        d[it] = d[v] + 1;
        dfs1(it, v);
        for (auto x: subtrees[it]) subtrees[v].push_back(x);
        G1.push_back(subtrees[it]);
    }

    int K = G1.size();
    for (int i = 0; i<K; i++)
        for (int j = i+1; j<K; j++)
        {
            for (auto v1: G1[i])
                for (auto v2: G1[j])
                {
                    int prob = dp[d[v1]-d[v]][d[v2]-d[v]];
                    if (v1>v2) ans = add(ans, prob);
                    else ans = add(ans, sub(1, prob));
                }
        }

    for (int i = 0; i<K; i++)
        for (auto v1: G1[i])
        {
            int prob = 1;
            if (v>v1) ans = add(ans, 1);
        }
}

void solve(int v)
{
    d.clear(); d.resize(n);
    subtrees.clear(); subtrees.resize(n);
    dfs1(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>n;
    G.resize(n);
    for (int i = 0; i<n-1; i++)
    {
        int u, v; cin>>u>>v; u--; v--; G[u].push_back(v); G[v].push_back(u);
    }

    dp = vector<vector<int>>(n, vector<int>(n));
    //probability that first wins

    for (int i = 0; i<n; i++) dp[0][i] = 1;
    for (int i = 1; i<n; i++)
        for (int j = 1; j<n; j++)
        {
            dp[i][j] = mul(inv2, add(dp[i-1][j], dp[i][j-1]));
        }

    for (int i = 0; i<n; i++) solve(i);

    ans = mul(ans, inv(n));
    cout<<ans<<endl;



}