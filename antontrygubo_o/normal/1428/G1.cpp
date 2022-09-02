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


vector<ll> F(6);
vector<ll> deg = {1, 10, 100, 1000, 10000, 100000};


ll cnt(int n)
{
    ll res = 0;
    for (int i = 0; i<6; i++)
    {
        int dig = n%10;
        if (dig%3==0) res+=(dig/3)*F[i];
        n/=10;
    }
    return res;
}

const int N = 1000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int k;
    cin>>k;
    k--;
    k*=3;
    for (int i = 0; i<6; i++) cin>>F[i];

    int q;
    cin>>q;
    int n;
    cin>>n;

    if (k==1)
    {
        cout<<cnt(n); return 0;
    }

    int d = 1;
    while ((1<<(d+2))-1<=k) d++;
    vector<ll> pows;
    for (int i = 0; i<=d; i++)
    {
        pows.push_back(1<<i);
        k-=(1<<i);
    }
    if (k>0) pows.push_back(k);

    vector<pair<ll, ll>> good;
    for (auto it: pows) for (int pos = 0; pos<6; pos++) if (1ll*it*3*deg[pos]<N) good.push_back(mp(it*3*deg[pos], it*F[pos]));

    vector<ll> dp(N, -1e18);
    dp[0] = 0;
    for (auto it: good)
    {
        for (int j = N-1; j>=it.first; j--) dp[j] = max(dp[j], dp[j-it.first] + it.second);
    }

    ll ans = -1e18;
    for (int i = 0; i<=n; i++) ans = max(ans, cnt(i) + dp[n - i]);
    cout<<ans;


}