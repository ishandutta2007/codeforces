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

void solve()
{
    vector<int> cnt(3);
    for (int i = 0; i<3; i++) cin>>cnt[i];
    vector<vector<ll>> a(3);
    for (int i = 0; i<3; i++)
    {
        //cout<<i<<": "<<endl;
        a[i].resize(cnt[i]);
        for (int j = 0; j<cnt[i]; j++) cin>>a[i][j];
        sort(a[i].begin(), a[i].end());
    }

    ll res = 2e18;

    vector<int> b = {0, 1, 2};

    do
    {
        for (auto y: a[b[1]])
        {
            if (a[b[2]].back()<y || a[b[0]][0]>y) continue;
            int z = *lower_bound(a[b[2]].begin(), a[b[2]].end(), y);
            int x = *prev(upper_bound(a[b[0]].begin(), a[b[0]].end(), y));
            res = min(res, 1ll*(x-y)*(x-y) + 1ll*(x-z)*(x-z) + 1ll*(z-y)*(z-y));
        }
    } while (next_permutation(b.begin(), b.end()));

    cout<<res<<endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) solve();

}

/*
 1
 2 2 3
7 8
6 3
3 1 4
 */