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
const int LIM = 300000;

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

int n;
vector<int> a, b;


bool check(int t)
{
    vector<int> a1(a.begin(), a.end());
    vector<int> b1(b.begin(), b.end());
    for (int i = 0; i<t; i++)
    {
        a1.push_back(100); b1.push_back(0);
    }
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());
    reverse(a1.begin(), a1.end());
    reverse(b1.begin(), b1.end());

    int suma = 0;
    int sumb = 0;
    int tot = n+t;
    tot = tot-(tot/4);

    for (int i = 0; i<tot; i++)
    {
        suma+=a1[i]; sumb+=b1[i];
    }
    return (suma>=sumb);

}

void solve()
{
    cin>>n;
    a.clear(); a.resize(n), b.clear(); b.resize(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int j = 0; j<n; j++) cin>>b[j];

    if (check(0)) {cout<<0<<endl; return;}
    int L = 0; int R = 3*n;
    while (R-L>1)
    {
        int mid = (L+R)/2; if (check(mid)) R = mid; else L = mid;
    }
    cout<<R<<endl;


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin>>t; while (t--) solve();


}