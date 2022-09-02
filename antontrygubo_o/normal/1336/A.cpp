#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 998244353;


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

/*struct DSU {
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
};*/

/*const int N = 1200000;

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
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}*/

vector<vector<int>> G;

vector<int> subtree, depth;

void dfs(int v, int par = -1)
{
    subtree[v] = 1;
    for (auto it: G[v]) if (it!=par)
    {
        depth[it] = depth[v] + 1;
        dfs(it, v);
        subtree[v]+=subtree[it];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    G.resize(n+1);
    int u, v;
    for (int i = 0; i<n-1; i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    subtree.resize(n+1);
    depth.resize(n+1);

    dfs(1);
    vector<int> guys;
    for (int i = 2; i<=n; i++)
    {
        guys.push_back(depth[i] - (subtree[i]-1));
    }
    sort(guys.begin(), guys.end());
    reverse(guys.begin(), guys.end());

    ll res = 0;
    for (int i = 0; i<k; i++) res+=guys[i];
    cout<<res;


}