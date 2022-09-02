#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")  //Enable AVX

using namespace std;

using ll = long long;

#define mp make_pair

const int p = 1e9 + 7;


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

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<ll> c(n);
    for (int i = 0; i<n; i++) cin>>c[i];

    int u, v;

    vector<pair<pair<int, int>, int>> hash(n);
    for (int i = 0; i<m; i++)
    {
        cin>>u>>v;
        u--; v--;
        hash[v].first.first = add(hash[v].first.first, po((u+2), 23));
        hash[v].first.second = add(hash[v].first.second, po((u+2), 47));
    }
    for (int i = 0; i<n; i++) hash[i].second = i;
    sort(hash.begin(), hash.end());

    /*for (int i = 0; i<n; i++)
    {
        cout<<hash[i].first.first<<' '<<hash[i].first.second<<endl;
    }*/

    ll res = 0;
    ll cur = 0;
    for (int i = 0; i<n; i++)
    {
        //cout<<hash[i].first.first<<' '<<hash[i].first.second<<endl;
        if (hash[i].first.first == 0 && hash[i].first.second == 0) continue;
        if (i>0 && hash[i].first!=hash[i-1].first)
        {
            res = __gcd(res, cur);
            cur = 0;
        }
        cur+=c[hash[i].second];
    }
    res = __gcd(res, cur);
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}