#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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


const int LIM = 400005;

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
}

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

vector<vector<pair<int, bool>>> G;
vector<bool> visited;
vector<int> color;

int cnt1, cnt2;

bool woke;

void dfs(int v)
{
    visited[v] = true;
    for (auto it: G[v])
    {
        if (visited[it.first])
        {
            if (it.second != (color[v] == color[it.first]))
            {
                woke = true;
                return;
            }
        }
        else
        {
            color[it.first] = color[v];
            if (!it.second) color[it.first] = 3 - color[it.first];
            if (color[it.first]==1) cnt1++;
            else cnt2++;
            dfs(it.first);
        }
    }
}

void solve()
{
    int n, m; cin>>n>>m;
    G.clear(); G.resize(n);
    visited.clear(); visited.resize(n);
    color.clear(); color.resize(n);
    woke = false;

    while (m--)
    {
        int u, v; string s;
        cin>>u>>v>>s;
        u--; v--;

        bool same = false;

        if (s=="crewmate") same = true;

        G[u].push_back(mp(v, same));
        G[v].push_back(mp(u, same));
    }

    int answer = 0;

    for (int i = 0; i<n; i++) if (!visited[i])
    {
        cnt1 = 0; cnt2 = 0;
        color[i] = 1;
        cnt1++;
        dfs(i);

        if (woke)
        {
            cout<<-1<<endl; return;
        }
        answer+=max(cnt1, cnt2);
    }

    cout<<answer<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}