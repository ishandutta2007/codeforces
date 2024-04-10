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
        }
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};

vector<vector<bool>> adj;
vector<vector<int>> G;



vector<int> solve(vector<vector<int>> g)
{
    int n = g.size();

    vector<int> deg(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            deg[i] += g[i][j];
    }

    int first = 0;
    while (first < n && !deg[first])
        ++first;


    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        if (deg[i] & 1) {
            if (v1 == -1)
                v1 = i;
            else if (v2 == -1)
                v2 = i;
            else
                bad = true;
        }
    }

    if (v1 != -1)
        ++g[v1][v2], ++g[v2][v1];

    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i)
            if (g[v][i])
                break;
        if (i == n) {
            res.push_back(v);
            st.pop();
        } else {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }

    if (v1 != -1) {
        for (size_t i = 0; i + 1 < res.size(); ++i) {
            if ((res[i] == v1 && res[i + 1] == v2) ||
                (res[i] == v2 && res[i + 1] == v1)) {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j])
                bad = true;
        }
    }

    return res;
}









int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;

    adj = vector<vector<bool>>(n, vector<bool>(n));

    G.resize(n);
    for (int i = 0; i<m; i++)
    {
        int u, v; cin>>u>>v; u--; v--;
        G[u].push_back(v); G[v].push_back(u);
        adj[u][v] = true; adj[v][u] = true;
    }

    vector<int> odd;
    for (int i = 0; i<n; i++) if (G[i].size()%2) odd.push_back(i);

    for (int root = 0; root<n; root++)
    {
        vector<int> odd1;
        for (auto it: odd) if (it!=root) odd1.push_back(it);

        if (odd1.size()==0) odd1.push_back(n);

        for (auto miss: odd1)
        {
            bool check = true;
            for (auto it: odd1) if (it!=miss)
            {
                if (!adj[root][it])
                {
                    check = false; break;
                }
            }
            if (!check) continue;

            set<pair<int, int>> banned_edges;
            for (auto it: odd1) if (it!=miss) banned_edges.insert(mp(root, it));

            DSU dsu(n);

            for (int i = 0; i<n; i++)
                for (auto v: G[i])
                {
                    if (banned_edges.count(mp(i, v)) || banned_edges.count(mp(v, i))) continue;
                    dsu.union_sets(i, v);
                }


            map<int, int> cnt_roots;
            for (int i = 0; i<n; i++) cnt_roots[dsu.find_set(i)]++;

            vector<int> szs;
            for (auto it: cnt_roots) szs.push_back(it.second);
            sort(szs.begin(), szs.end());
            if (szs.size()>=2 && szs[szs.size()-2]>=2) check = false;

            if (!check) continue;


            vector<vector<int>> g(n, vector<int>(n));

            for (int i = 0; i<n; i++)
                for (auto v: G[i])
                {
                    if (banned_edges.count(mp(i, v)) || banned_edges.count(mp(v, i))) continue;
                    g[i][v] = 1;
                }

            auto path = solve(g);

            if (path[0]==root) reverse(path.begin(), path.end());

            if (path.back()!=root)
            {
                int len = path.size();
                int pos = 0;
                while (path[pos]!=root) pos++;

                vector<int> path1;
                for (int i = pos; pos<len; len++) path1.push_back(path[i]);
                for (int i = 1; i<=pos; i++) path1.push_back(path[i]);
                path = path1;
            }


            path.push_back(-2);
            for (auto it: odd1) if (it!=miss)
            {
                path.push_back(it); path.push_back(root);
            }

            cout<<path.size()<<endl; for (auto it: path) cout<<it+1<<' ';
            return 0;

        }

    }

    cout<<0;

}