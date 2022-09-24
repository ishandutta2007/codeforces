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

ll t[1200000];

void build()
{
    for (ll i=0;i<1200000;i++) t[i] = 0;
}

void upd(ll v, ll tl, ll tr, ll p, ll d)
{
    t[v] += d;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (tm>=p) upd(v*2,tl,tm,p,d);
    else upd(v*2+1,tm+1,tr,p,d);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll x = 0;
    if (tm>=l) x += get(v*2,tl,tm,l,r);
    if (tm<r) x += get(v*2+1,tm+1,tr,l,r);
    return x;
}


void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    ll mx = 210000;
    ll A = 0;
    ll C = 1;
    vector<ll> f(mx+1), f2(mx+1), obr(mx+1);
    f[0] = f2[0] = 1;
    for (ll i=1;i<=mx;i++)
    {
        f[i] = f[i-1]*i%mod;
        f2[i] = pew(f[i],mod-2);
        obr[i] = pew(i,mod-2);
    }
    C = f[n];
    vector<ll> c(mx+1);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    build();
    for (ll i=1;i<=mx;i++)
    {
        upd(1,0,mx,i,c[i]);
        C = C*f2[c[i]]%mod;
    }
    for (ll i=0;i<m;i++) cin >> b[i];
    ll L = n;
    for (ll z=0;z<m;z++)
    {
        ll x = b[z];
        if (L==0)
        {
            A = (A+1)%mod;
            break;
        }
        ll Q = get(1,0,mx,0,x-1);
        A = (A+Q*obr[L]%mod*C)%mod;
        if (c[x]==0) break;
        C = C*c[x]%mod*obr[L]%mod;
        L--;
        c[x]--;
        upd(1,0,mx,x,-1);
    }
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> t;
    while (T--) solve();
}