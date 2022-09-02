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


const int MOD =  998244353;

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


/*const int LIM = 1e6 + 5;

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
        find_set(a);
        find_set(b);

        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

vector<vector<int>> G;

vector<vector<int>> dp;

int n, k;

void dfs(int v, int par = -1)
{
    vector<int> cur = {1};
    for (auto it: G[v]) if (it!=par)
    {
        dfs(it, v);
        int len = dp[it].size();

        int maxx = max(len, (int)cur.size()) + 1;
        maxx = min(maxx, k+1);

        vector<int> new_cur(maxx);

        for (int i = 0; i<cur.size(); i++)
            for (int j = 0; j<len; j++)
            {
                //Adding edge:
                if (i+j+1<=k) new_cur[max(i, j+1)] = add(new_cur[max(i, j+1)], mul(cur[i], dp[it][j]));
                //Not adding edge:
                new_cur[i] = add(new_cur[i], mul(cur[i], dp[it][j]));
            }
        cur = new_cur;
    }
    dp[v] = cur;
}

void solve()
{
    cin>>n>>k;
    G.resize(n);

    dp.resize(n);
    for (int i = 0; i<n-1; i++)
    {
        int u, v; cin>>u>>v; u--; v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    dfs(0);

    int ans = 0;
    for (auto it: dp[0]) ans = add(ans, it);
    cout<<ans<<endl;



}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);



    int t = 1; while (t--) solve();


}

/*
1
1100
 */