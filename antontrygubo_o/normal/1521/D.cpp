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


vector<vector<int>> G;

vector<vector<int>> ans;
vector<int> connect1;
vector<pair<int, int>> connect2;

void dfs(int v, int par = -1)
{
    for (auto it: G[v]) if (it!=par)
    {
        dfs(it, v);
    }

    //Calculating ans[0]
    for (auto it: G[v]) if (it!=par)
    {
        ans[v][0]+=max({ans[it][0], ans[it][1], ans[it][2]});
    }

    vector<pair<int, int>> diff;

    for (auto it: G[v]) if (it!=par)
    {
        diff.push_back(mp(max(ans[it][0], ans[it][1]) - max({ans[it][0], ans[it][1], ans[it][2]}), it));
    }

    sort(diff.begin(), diff.end()); reverse(diff.begin(), diff.end());

    //Calculating ans[1]: Connecting exactly 1

    ans[v][1] = ans[v][0];

    if (diff.size()>=1)
    {
        ans[v][1]+=(1+diff[0].first);
        connect1[v] = diff[0].second;
    }
    else ans[v][1] = -1e9;

    //Calculating ans[2]: Connecting exactly 2

    ans[v][2] = ans[v][0];

    if (diff.size()>=2)
    {
        ans[v][2]+=(1+diff[0].first);
        ans[v][2]+=(1+diff[1].first);
        connect2[v] = mp(diff[0].second, diff[1].second);
    }
    else ans[v][2] = -1e9;
}

set<pair<int, int>> edges;

void restore(int v, int maxx, int par = -1)
{
    int opt = 0;
    if (ans[v][1]>ans[v][opt]) opt = 1;
    if (maxx==2 && ans[v][2]>ans[v][opt]) opt = 2;

    if (opt==0)
    {
        for (auto it: G[v]) if (it!=par) restore(it, 2, v);
    }

    if (opt==1)
    {
        for (auto it: G[v]) if (it!=par)
        {
            if (it!=connect1[v]) restore(it, 2, v);
            else
            {
                edges.insert(mp(v, it));
                restore(it, 1, v);
            }
        }
    }

    if (opt==2)
    {
        for (auto it: G[v]) if (it!=par)
            {
                if (it!=connect2[v].first && it!=connect2[v].second) restore(it, 2, v);
                else
                {
                    edges.insert(mp(v, it));
                    restore(it, 1, v);
                }
            }
    }
}



void solve()
{
    edges.clear();
    int n; cin>>n;
    G.clear(); G.resize(n);

    for (int i = 0; i<n-1; i++)
    {
        int u, v; cin>>u>>v; u--; v--; G[u].push_back(v); G[v].push_back(u);
    }

    ans.clear();
    ans = vector<vector<int>>(n, vector<int>(3));
    connect1.clear(); connect1 = vector<int>(n);
    connect2.clear(); connect2 = vector<pair<int, int>>(n);

    dfs(0);

    /*for (int i = 0; i<n; i++)
    {
        for (auto it: ans[i]) cout<<it<<' ';
        cout<<endl;
    }*/

    restore(0, 2);

    //for (auto it: edges) cout<<it.first<<' '<<it.second<<endl;

    vector<pair<int, int>> to_del;

    for (int i = 0; i<n; i++)
    {
        for (auto it: G[i]) if (it>i)
        {
            if (edges.count(mp(i, it))||edges.count(mp(it, i))) continue;
            else to_del.push_back(mp(i, it));
        }
    }

    //for (auto it: to_del) cout<<it.first<<' '<<it.second<<endl;


    vector<int> deg(n);
    DSU dsu(n);

    for (auto it: edges)
    {
        deg[it.first]++; deg[it.second]++;
        dsu.union_sets(it.first, it.second);
    }

    map<int, vector<int>> roots;

    for (int i = 0; i<n; i++) roots[i] = vector<int>();

    for (int i = 0; i<n; i++) if (deg[i]<2)
    {
        roots[dsu.find_set(i)].push_back(i);
    }

    vector<int> bruh;
    for (auto it: roots)
    {
        auto vec = it.second;
        if (vec.size()==1)
        {
            bruh.push_back(vec[0]); bruh.push_back(vec[0]);
        }
        else if (vec.size()==2)
        {
            bruh.push_back(vec[0]); bruh.push_back(vec[1]);
        }
    }

    vector<pair<int, int>> to_add;

    int K = to_del.size();
    for (int i = 1; i<=2*K-1; i+=2)  to_add.push_back(mp(bruh[i], bruh[i+1]));


    cout<<K<<endl;
    for (int i = 0; i<K; i++) cout<<to_del[i].first+1<<' '<<to_del[i].second+1<<' '<<to_add[i].first+1<<' '<<to_add[i].second+1<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();

}

/*
1
7
1 2
1 3
2 4
2 5
3 6
3 7
 */