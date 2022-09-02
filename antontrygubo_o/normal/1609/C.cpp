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

const int N = 1'000'000;

vector<bool> is_prime(N+1, 1);

vector<int> primes;

void print(vector<int> a)
{
    for (auto it: a) cout<<it<<' ';
    cout<<endl;
}

ll cnt(vector<int> a)
{
    int n = a.size();
    vector<int> ones_left(n), ones_right(n);
    for (int i = 1; i<n; i++)
    {
        if (a[i-1]!=1) ones_left[i] = 0;
        else ones_left[i] = ones_left[i-1] + 1;
    }
    for (int i = n-2; i>=0; i--)
    {
        if (a[i+1]!=1) ones_right[i] = 0;
        else ones_right[i] = ones_right[i+1] + 1;
    }

    ll ans = 0;
    for (int i = 0; i<n; i++) if (is_prime[a[i]])
    {
        ans+=1ll*(ones_left[i]+1)*(ones_right[i]+1);
        ans--;
    }

    /*print(a);
    print(ones_left);
    print(ones_right);
    cout<<ans<<endl;*/

    return ans;
}

void solve()
{
    int e, n; cin>>n>>e;

    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];

    ll ans = 0;

    for (int rem = 0; rem<e; rem++)
    {
        vector<int> guys;
        for (int i = rem; i<n; i+=e) guys.push_back(a[i]);
        ans+=cnt(guys);
    }

    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    is_prime[1] = false;
    for (int i = 2; i<=N; i++) if (is_prime[i])
    {
        if (i<=N/i)
        {
            for (int j = i*i; j<=N; j+=i) is_prime[j] = false;
        }
    }

    int t; cin>>t;
    while (t--) solve();
}
/*
1
7 3
10 2 1 3 1 19 3
 */