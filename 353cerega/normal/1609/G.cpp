#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;

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


ll t[1200000], del[1200000], t2[1200000];

void build()
{
    for (ll i=0;i<1200000;i++) t[i] = del[i] = t2[i] = 0;
}

void push(ll v, ll tl, ll tr, ll tm)
{
    t[2*v] += del[v];
    t2[2*v] += del[v]*(tm-tl+1);
    del[2*v] += del[v];
    t[2*v+1] += del[v];
    t2[2*v+1] += del[v]*(tr-tm);
    del[2*v+1] += del[v];
    del[v] = 0;
}

void upd(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (tl>=l and tr<=r)
    {
        t[v] += val;
        del[v] += val;
        t2[v] += (tr-tl+1)*val;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    if (tm>=l) upd(v*2,tl,tm,l,r,val);
    if (tm<r) upd(v*2+1,tm+1,tr,l,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
    t2[v] = t2[2*v]+t2[2*v+1];
}

ll get(ll v, ll tl, ll tr, ll x)
{
    if (tl==tr)
    {
        return tl;
    }
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    if (t[v*2+1]>=x) return get(v*2,tl,tm,x);
    else return get(2*v+1,tm+1,tr,x);
}

ll get2(ll v, ll tl, ll tr, ll p)
{
    if (tr<=p) return t2[v];
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    if (tm>=p) return get2(v*2,tl,tm,p);
    else return t2[2*v]+get2(2*v+1,tm+1,tr,p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    vector<ll> b(m);
    for (ll i=0;i<n;i++) cin >> a[i];
    for (ll j=0;j<m;j++) cin >> b[j];
    ll S = a[0]+b[0];
    for (ll i=n-1;i>0;i--) a[i] = a[i]-a[i-1];
    for (ll i=m-1;i>0;i--) b[i] = b[i]-b[i-1];
    build();
    ll S2 = 0;
    for (ll i=1;i<m;i++)
    {
        upd(1,0,m-1,i,i,b[i]);
        S2 += b[i]*(m-i);
    }
    while (q--)
    {
        ll z, k, d;
        cin >> z >> k >> d;
        if (z==1)
        {
            if (k==n)
            {
                S += d;
                k--;
            }
            for (ll i=n-k;i<n;i++) a[i] += d;
        }
        else
        {
            if (k==m)
            {
                S += d;
                k--;
            }
            upd(1,0,m-1,m-k,m-1,d);
            S2 += k*(k+1)/2*d;
        }
        ll R = S*(n+m-1)+S2;
        for (ll i=1;i<n;i++)
        {
            ll p = get(1,0,m-1,a[i]);
            R += a[i]*(m+n-1-p-i);
            R += get2(1,0,m-1,p);
        }
        cout << R << "\n";
    }
}