#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2")

using namespace std;

using ll = long long;
using ld = long double;

#define mp make_pair

const int p = 1000000007;


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
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}

    vector<int> cnt(n, 1);

    vector<int> pos(n);
    for (int i = 0; i<n; i++) pos[a[i]] = i;

    set<int> free;
    for (int i = 0; i<n; i++) free.insert(i);

    set<pair<int, int>> res;
    for (int i = 0; i<n; i++) res.insert(mp(1, i));

    for (int i = 0; i<n; i++)
    {
        int maxx = prev(res.end())->first;
        //cout<<maxx<<endl;
        if (cnt[pos[i]]!=maxx) {cout<<"No"<<endl; return;}
        free.erase(pos[i]);
        res.erase(mp(cnt[pos[i]], pos[i]));
        auto it = free.lower_bound(pos[i]);
        if (it!=free.end())
        {
            int x = *it;
            res.erase(mp(cnt[x], x));
            cnt[x] += maxx;
            res.insert(mp(cnt[x], x));
        }

    }
    cout<<"Yes"<<endl;
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
3
1 3 2
 */