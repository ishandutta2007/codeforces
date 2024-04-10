#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a==0 or b==0) return a+b;
    return gcd(b,a%b);
}


ll sum(ll a, ll b)
{
    a += b;
    if (a>=mod) a -= mod;
    //a %= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a += mod-b;
    a %= mod;
    return a;
}

inline ll mul(ll a, ll b)
{
    if (a*b<mod) return a*b;
    else return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1LL) res = mul(res,a);
        a = mul(a,a);
        b >>= 1LL;
    }
    return res;
}



/*const int MOD = 998244353;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;
const int root = 30;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*
void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pew(n, mod-2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}*/


/*
int parent[1200001];
int rnk[1200001];

void make_set (int v) {
    parent[v] = v;
    rnk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets (int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}*/


ll M = 58;
vector<vector<ll>> Q;
vector<ll> a;
vector<vector<ll>> bad;

vector<ll> was;
vector<ll> lul = {29,31,37,41,43,47,53,59};
ll D = 0;

void rec(ll p)
{
    Q.push_back(a);
    for (;p<=M;p++)
    {
        ll F = 0;
        for (ll j=0;j<a.size();j++)
        {
            if (bad[a[j]][p]==1)
            {
                F = 1;
                break;
            }
        }
        if (F==1) continue;
        if (was[p]==1 and p!=lul[D]) continue;
        if (was[p]==1) D++;
        a.push_back(p);
        rec(p+1);
        a.pop_back();
        if (was[p]==1) D--;
    }
}

void solve()
{
    bad.resize(M+1,vector<ll>(M+1));
    was.resize(M+1);
    was[29] = was[31] = was[37] = was[41] = was[43] = was[47] = was[53] = 1;
    for (ll i=1;i<=M;i++)
    {
        for (ll j=1;j<=M;j++)
        {
            if (gcd(i,j)>1) bad[i][j] = 1;
        }
    }
    rec(2);
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<pair<ll,ll>> ord(n);
    for (ll i=0;i<n;i++)
    {
        cin >> x[i];
        ord[i] = {x[i],i};
    }
    sort(ord.begin(),ord.end());
    a.clear();
    a.resize(n);
    for (ll i=0;i<n;i++) a[i] = ord[i].X;
    ll mn = mod;
    vector<ll> A(n,1);
    for (auto kek: Q)
    {
        if (kek.size()>n) continue;
        ll S = 0;
        ll sz = kek.size();
        for (ll i=0;i<sz;i++)
        {
            S += abs(kek[sz-1-i]-a[n-1-i]);
        }
        for (ll i=sz;i<n;i++)
        {
            S += a[n-1-i]-1;
        }
        if (S<mn)
        {
            mn = S;
            A.clear();
            A.resize(n-sz,1);
            for (ll w: kek)
            {
                A.push_back(w);
            }
        }
    }
    vector<ll> ans(n);
    for (ll i=0;i<n;i++)
    {
        ans[ord[i].Y] = A[i];
    }
    for (ll i=0;i<n;i++) cout << ans[i] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}