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
    a %= mod;
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
    return a*b%mod;
}

inline ll pew(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = mul(res,a);
        a = mul(a,a);
        b /= 2;
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


ll t[200000], del[200000];

void build()
{
    for (ll i=0;i<200000;i++)
    {
        t[i] = 0;
        del[i] = 0;
    }
}

void push(ll v)
{
    t[2*v] += del[v];
    t[2*v+1] += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}

void add(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (tl>=l and tr<=r)
    {
        t[v] += val;
        del[v] += val;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v);
    if (tm>=l) add(v*2,tl,tm,l,r,val);
    if (tm<r) add(v*2+1,tm+1,tr,l,r,val);
    t[v] = min(t[v*2],t[v*2+1]);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    push(v);
    ll x = mod*mod;
    if (tm>=l) x = min(x,get(v*2,tl,tm,l,r));
    if (tm<r) x = min(x,get(v*2+1,tm+1,tr,l,r));
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> prv(n+1,-1);
    vector<pair<ll,ll>> ord;
    for (ll i=1;i<=n;i++)
    {
        ll x;
        cin >> x;
        ord.push_back({x,i});
    }
    sort(ord.begin(),ord.end());
    for (ll i=0;i<ord.size();i++)
    {
        if (i!=0 and ord[i].X==ord[i-1].X)
        {
            prv[ord[i].Y] = ord[i-1].Y;
        }
    }
    vector<ll> dp(n+1,mod*mod);
    dp[0] = 0;
    for (ll q=0;q<k;q++)
    {
        build();
        vector<ll> dp2(n+1);
        for (ll i=0;i<=n;i++)
        {
            if (prv[i]!=-1)
            {
                add(1,0,n,0,prv[i]-1,i-prv[i]);
            }
            add(1,0,n,i,i,dp[i]);
            dp2[i] = get(1,0,n,0,i);
        }
        dp = dp2;
    }
    cout << dp[n] << endl;
}