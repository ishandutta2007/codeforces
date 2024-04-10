#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


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


mt19937 rnd(time(0));

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
    if (n<0 || k<0) return 0;
    return mul(facs[n], mul(invfacs[k], invfacs[n-k]));
}

*/


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

    DSU (int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i<n; i++) make_set(i);
    }
};*/



ll ans(ll len, ll parts)
{
    ll part = len/parts;
    ll bad = len%parts;
    return part*part*(parts-bad) + (part+1)*(part+1)*bad;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    vector<int> current(n, 1);

    set<pair<ll, int>> diff;
    for (int i = 0; i<n; i++) if (a[i]>1) diff.insert(mp(ans(a[i], 1) - ans(a[i], 2), i));

    /*for (auto it: diff) cout<<it.first<<' '<<it.second<<endl;
    cout<<"ROUND"<<endl;*/

    for (int i = 0; i<k-n; i++)
    {
        auto it = *prev(diff.end());
        diff.erase(it);
        current[it.second]++;
        if (current[it.second]<a[it.second]) diff.insert(mp(ans(a[it.second], current[it.second]) - ans(a[it.second], current[it.second]+1), it.second));
    }


    ll res = 0;
    for (int i = 0; i<n; i++) res+=ans(a[i], current[i]);
    cout<<res;

}