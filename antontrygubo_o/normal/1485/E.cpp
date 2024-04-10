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


const int p =  1e9 + 7;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    if (s>=p) s-=p;
    return s;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
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
    return po(n, p-2);
}


mt19937 rnd(time(0));

/*
const int N = 1e6 + 5;

vector<int> facs(N), invfacs(N);

void init()
{
    facs[0] = 1;
    for (int i = 1; i<N; i++) facs[i] = mul(facs[i-1], i);
    invfacs[N-1] = inv(facs[N-1]);
    for (int i = N-2; i>=0; i--) invfacs[i] = mul(invfacs[i+1], i+1);
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
    vector<int> value;
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        value[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        else
        {
            auto par = find_set(parent[v]);
            value[v]^=value[parent[v]];
            parent[v] = par;
            return par;
        }
    }

    void union_sets(int a, int b, int w) {
        find_set(a);
        find_set(b);

        w^=value[a]; w^=value[b];
        a = find_set(a);
        b = find_set(b);

        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            value[b] = w;
            sz[a] += sz[b];
        }
    }

    int val(int v)
    {
        find_set(v); return value[v];
    }

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        value.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/

vector<vector<int>> G;
vector<int> depth, parent;

void dfs(int v, int par = -1)
{
    for (auto it: G[v]) if (it!=par)
    {
        depth[it] = depth[v]+1;
        parent[it] = v;
        dfs(it, v);
    }
}

void solve()
{
    int n; cin>>n;
    G.clear();
    G.resize(n);
    for (int i = 1; i<=n-1; i++)
    {
        int v; cin>>v; v--;
        G[v].push_back(i); G[i].push_back(v);
    }

    vector<int> a(n); for (int i = 1; i<n; i++) cin>>a[i];

    depth.clear(); depth.resize(n);
    parent.clear(); parent.resize(n);

    dfs(0);

    int maxx = 0; for (auto it: depth) maxx = max(maxx, it);

    vector<ll> answer(n);

    vector<vector<int>> layers(maxx+1);
    for (int i = 0; i<n; i++) layers[depth[i]].push_back(i);

    for (int d = 1; d<=maxx; d++)
    {
        vector<pair<pair<int, ll>, int>> tmp;
        for (auto it: layers[d]) tmp.push_back(mp(mp(a[it], answer[parent[it]]), it));
        sort(tmp.begin(), tmp.end());

        ll maxx_low = -1e18;
        for (auto it: tmp)
        {
            maxx_low = max(maxx_low, it.first.second - it.first.first);
            answer[it.second] = max(answer[it.second], maxx_low + it.first.first);
        }

        reverse(tmp.begin(), tmp.end());
        ll maxx_high = -1e18;
        for (auto it: tmp)
        {
            maxx_high = max(maxx_high, it.first.second + it.first.first);
            answer[it.second] = max(answer[it.second], maxx_high - it.first.first);
        }

        for (auto it: tmp) answer[it.second] = max(answer[it.second],
                answer[parent[it.second]] + max(abs(it.first.first - tmp[0].first.first), abs(it.first.first - tmp.back().first.first)));

    }

    ll res = 0; for (auto it: answer) res = max(res, it);
    cout<<res<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t;
    while (t--) solve();
}