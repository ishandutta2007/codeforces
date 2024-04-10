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

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;

    vector<string> s(n);
    for (int i = 0; i<n; i++) cin>>s[i];

    vector<int> a(m); for (int i = 0; i<m; i++) cin>>a[i];

    int cur = 0;
    map<pair<int, int>, int> mapka;
    map<int, pair<int, int>> mapka1;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
        {
            if (s[i][j]=='#')
            {
                mapka[mp(i, j)] = cur;
                mapka1[cur] = mp(i, j);
                cur++;
            }
        }

    adj.resize(cur);
    adj_rev.resize(cur);

    vector<int> down(m, -1);
    for (int i = n-1; i>=0; i--)
    {
        for (int j = 0; j<m; j++) if (s[i][j]=='#')
        {
            vector<pair<int, int>> cells;
            if (j>0 && s[i][j-1]=='#') cells.push_back(mp(i, j-1));
            if (j+1<m && s[i][j+1]=='#') cells.push_back(mp(i, j+1));
            //if (i>0 && s[i-1][j]=='#') cells.push_back(mp(i-1, j));
            if (i-1>=0 && s[i-1][j]=='#') cells.push_back(mp(i-1, j));

            if (j-1>=0 && down[j-1]!=-1) cells.push_back(mp(down[j-1], j-1));
            if (down[j]!=-1) cells.push_back(mp(down[j], j));
            if (j+1<m && down[j+1]!=-1) cells.push_back(mp(down[j+1], j+1));

            int val = mapka[mp(i, j)];

            for (auto cell: cells)
            {
                int val1 = mapka[cell];
                adj[val].push_back(val1);
                adj_rev[val1].push_back(val);
            }
        }
        for (int j = 0; j<m; j++) if (s[i][j]=='#') down[j] = i;
    }


    /*cout<<cur<<endl;
    for (int i = 0; i<cur; i++)
    {
        cout<<i<<": "; for (auto it: adj[i]) cout<<it<<' ';
        cout<<endl;
    }*/

    used.assign(cur, false);
    for (int i = 0; i < cur; i++)
        if (!used[i])
            dfs1(i);

    used.assign(cur, false);
    reverse(order.begin(), order.end());

    int curcomp = 0;
    vector<int> comps(cur);

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            for (auto it: component) comps[it] = curcomp;
            curcomp++;
            component.clear();
        }

    vector<int> L(curcomp, m);
    vector<int> R(curcomp, -1);

    for (int i = 0; i<cur; i++)
    {
        L[comps[i]] = min(L[comps[i]], mapka1[i].second);
        R[comps[i]] = max(R[comps[i]], mapka1[i].second);
    }

    vector<int> covering;
    for (auto it: order)
    {
        for (auto v: adj[it])
        {
            L[comps[v]] = min(L[comps[v]], L[comps[it]]);
            R[comps[v]] = max(R[comps[v]], R[comps[it]]);
        }
    }

    vector<pair<int, int>> segs;

    for (int i = 0; i<m; i++) if (a[i]>0)
    {
        int cnt = 0;
        int pos = n;
        while (cnt<a[i])
        {
            pos--; if (s[pos][i]=='#') cnt++;
        }
        int v = mapka[mp(pos, i)];
        segs.push_back(mp(L[comps[v]], R[comps[v]]));
    }


    vector<bool> in(curcomp, false);
    for (int i = 0; i<cur; i++)
        for (auto v: adj[i])
        {
            if (comps[i]!=comps[v]) in[comps[v]] = true;
        }

    vector<pair<int, int>> starts;

    for (int i = 0; i<curcomp; i++) if (!in[i]) starts.push_back(mp(L[i], R[i]));

    sort(starts.begin(), starts.end());

    /*cout<<"STARTS"<<endl;
    for (auto it: starts) cout<<it.first<<' '<<it.second<<endl;

    cout<<"NEED"<<endl;
    for (auto it: segs) cout<<it.first<<' '<<it.second<<endl;*/

    int GOOD = starts.size();
    vector<pair<int, int>> segs1;
    for (auto it: segs)
    {
        auto st = lower_bound(starts.begin(), starts.end(), mp(it.first, -1)) - starts.begin();
        auto en = upper_bound(starts.begin(), starts.end(), mp(it.second+1, -1)) - starts.begin() - 1;
        segs1.push_back(mp(st, en));
    }

    /*cout<<"GOOD"<<endl;
    for (auto it: segs1) cout<<it.first<<' '<<it.second<<endl;*/

    for (auto &it: segs1) swap(it.first, it.second);
    sort(segs1.begin(), segs1.end());

    int last = -1;

    int ans = 0;
    for (auto it: segs1)
    {
        if (last>=it.second) continue;
        else
        {
            last = it.first; ans++;
        }
    }

    cout<<ans<<endl;

}