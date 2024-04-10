#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

int MOD =  998244353;

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


const int LIM = 400005;

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
}

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

const int N = 5e5 + 10;

vector<int> degs(N);

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];


    int cnt1 = 0;
    for (int i = 0; i<n; i++) if (a[i]==1) cnt1++;

    int ans = sub(degs[cnt1], 1);

    vector<int> good_end(n), bad_end(n);
    vector<int> sum_good_end(n+1);

    for (int i = 0; i<n; i++)
    {
        good_end[i] = sum_good_end[a[i]];
        if (a[i]>0) good_end[i] = add(good_end[i], sum_good_end[a[i]-1]);
        else good_end[i] = add(good_end[i], 1);
        if (a[i]>1) bad_end[i] = sum_good_end[a[i]-2];
        ans = add(ans, good_end[i]);

        sum_good_end[a[i]] = add(sum_good_end[a[i]], good_end[i]);
    }

    vector<int> cnt(n+1);
    for (int i = n-1; i>=0; i--)
    {
        int ways = cnt[a[i]];
        if (a[i]>=2) ways = add(ways, cnt[a[i]-2]);
        ans = add(ans, mul(bad_end[i], degs[ways]));
        cnt[a[i]]++;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    degs[0] = 1;
    for (int i = 1; i<N; i++) degs[i] = add(degs[i-1], degs[i-1]);

    int t; cin>>t;
    while (t--) solve();

}