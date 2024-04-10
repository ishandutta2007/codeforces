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


ll t[1200000];

void build(ll n)
{
    for (ll i=0;i<4*n+100;i++)
    {
        t[i] = 0;
    }
}

void upd(ll v, ll tl, ll tr, ll p, ll val)
{
    t[v] = (t[v]+val)%mod;
    if (tl==tr) return;
    ll tm = (tl+tr)/2;
    if (tm>=p) upd(v*2,tl,tm,p,val);
    else upd(v*2+1,tm+1,tr,p,val);
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l>r) return 0;
    if (tl>=l and tr<=r) return t[v];
    ll tm = (tl+tr)/2;
    ll x = 0;
    if (tm>=l) x += get(v*2,tl,tm,l,r);
    if (tm<r) x += get(v*2+1,tm+1,tr,l,r);
    x %= mod;
    return x;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll S = -1;
    {
        vector<pair<ll,ll>> ord(n);
        for (ll i=0;i<n;i++) ord[i] = {a[i],i};
        sort(ord.begin(),ord.end());
        for (ll i=0;i<n;i++)
        {
            if (i==0 or ord[i].X!=ord[i-1].X) S++;
            a[ord[i].Y] = S;
        }
    }
    build(n);
    vector<ll> A(n), B(n), C(n);
    for (ll i=0;i<n;i++)
    {
        ll x = get(1,0,S,0,a[i]-1);
        x = (x+1)%mod;
        A[i] = x;
        upd(1,0,S,a[i],A[i]);
    }
    build(n);
    for (ll i=n-1;i>=0;i--)
    {
        ll x = get(1,0,S,a[i]+1,S);
        x = (x+1)%mod;
        B[i] = x;
        upd(1,0,S,a[i],B[i]);
    }
    build(n);
    for (ll i=0;i<n;i++)
    {
        ll x = get(1,0,S,0,a[i]-1);
        x = (x+A[i])%mod;
        C[i] = x;
        upd(1,0,S,a[i],C[i]);
    }
    set<pair<ll,ll>> kek;
    for (ll i=0;i<n;i++) kek.insert({a[i],-i});
    ll prv = -1;
    ll ans = 0;
    build(n);
    for (ll i=n-1;i>=0;i--)
    {
        if (a[i]<=prv) continue;
        prv = a[i];
        vector<ll> q;
        while (true)
        {
            if (kek.size()==0) break;
            ll p = -kek.begin()->Y;
            if (a[p]>=a[i]) break;
            kek.erase({a[p],-p});
            if (p>i) continue;
            ans = (ans+A[p]*B[p])%mod;
            q.push_back(p);
        }
        ll sz = q.size();
        vector<ll> W(sz);
        for (ll j=0;j<sz;j++)
        {
            ll p = q[j];
            W[j] = get(1,0,n-1,0,p-1);
            W[j] = (W[j]+A[p])%mod;
            ans = (ans+mod-W[j])%mod;
            upd(1,0,n-1,p,W[j]);
        }
        for (ll j=0;j<sz;j++)
        {
            ll p = q[j];
            upd(1,0,n-1,p,-W[j]);
        }
    }
    if (ans<0) ans += mod;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}