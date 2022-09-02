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

/*
const int LIM = 1e6 + 5;

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
        else
        {
            auto par = find_set(parent[v]);
            parent[v] = par;
            return par;
        }
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

const int INF = 1e9;

vector<vector<int>> G;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;
    vector<vector<int>> d(n, vector<int>(n, INF));

    G.resize(n);

    for (int i = 0; i<n; i++) d[i][i] = 0;

    for (int i = 0; i<m; i++)
    {
        int u, v; cin>>u>>v; u--; v--;
        G[u].push_back(v); G[v].push_back(u);
        d[u][v] = 1; d[v][u] = 1;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i<n; i++)
    {
        ans[i][i] = 1;
        for (int v = 0; v<n; v++) if (v!=i)
        {
            int cnt = 0;
            for (auto v1: G[v]) if (d[i][v1] + 1 == d[i][v]) cnt++;
            ans[i][i] = mul(ans[i][i], cnt);
        }
    }

    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++)
        {
            int cntpath = 0;
            for (int v = 0; v<n; v++) if (d[i][v] + d[v][j] == d[i][j]) cntpath++;

            if (cntpath!=d[i][j]+1) continue;

            int tmp = 1;
            for (int v = 0; v<n; v++) if (d[i][v] + d[v][j] != d[i][j])
            {
                int cnt = 0;
                for (auto v1: G[v]) if (d[i][v1] + 1 == d[i][v] && d[j][v1] + 1 == d[j][v]) cnt++;
                tmp = mul(tmp, cnt);
            }
            ans[i][j] = tmp; ans[j][i] = tmp;
        }

    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}