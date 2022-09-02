#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


const int p = 1e7;


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

int po(int a, int deg)
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

struct DSU {
    vector<int> sz;
    vector<int> parent;

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
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

    DSU(int n) {
        sz.resize(n);
        parent.resize(n);
        for (int i = 0; i < n; i++) make_set(i);
    }
};

/*
const int N = 1200000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}
*/

vector<vector<int>> G;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    G.resize(n+1);
    for (int i = 0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> colors(n+1);
    for (int i = 1; i<=n; i++) cin>>colors[i];

    vector<pair<int, int>> t(n+1);

    for (int i = 1; i<=n; i++)
    {
        t[i].first = colors[i];
        t[i].second = i;
    }
    sort(t.begin(), t.end());

    for (auto it: t) if (it.second!=0)
    {
        vector<bool> check(it.first+1);
        for (auto v: G[it.second]) if (colors[v]<=it.first) check[colors[v]] = true;
        for (int i = 1; i<it.first; i++) if (!check[i]) {cout<<-1; return 0;}
        if (check[it.first]) {cout<<-1; return 0;}
    }

    for (auto it: t) if (it.second!=0) cout<<it.second<<' ';




}