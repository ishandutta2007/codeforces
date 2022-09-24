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

vector<ll> dp;
vector<ll> a;
vector<ll> rev, sw;

void build(ll v, ll tl, ll tr)
{
    if (tl+1==tr)
    {
        dp[v] = a[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm,tr);
    dp[v] = dp[v*2]+dp[v*2+1];
}

void upd(ll v, ll tl, ll tr, ll p, ll val, ll D)
{
    if (tl+1==tr)
    {
        dp[v] = val;
        return;
    }
    ll tm = (tl+tr)/2;
    if (sw[D]==1)
    {
        if (p>=tm) p -= (1LL<<D);
        else p += (1LL<<D);
    }
    if (rev[D]==1) p = tr-1+tl-p;
    if (p<tm) upd(v*2,tl,tm,p,val,D-1);
    else upd(v*2+1,tm,tr,p,val,D-1);
    dp[v] = dp[v*2]+dp[v*2+1];
}

ll get(ll v, ll tl, ll tr, ll l, ll r, ll D)
{
    if (tl==l and tr==r)
    {
        return dp[v];
    }
    ll tm = (tl+tr)/2;
    if (l<tm and r>tm)
    {
        return get(v,tl,tr,l,tm,D)+get(v,tl,tr,tm,r,D);
    }
    if (sw[D]==1)
    {
        if (l>=tm) l -= (1LL<<D);
        else l += (1LL<<D);
        if (r>tm) r -= (1LL<<D);
        else r += (1LL<<D);
    }
    if (rev[D]==1)
    {
        l = tr+tl-l;
        r = tr+tl-r;
        swap(l,r);
    }
    if (r<=tm) return get(v*2,tl,tm,l,r,D-1);
    else return get(v*2+1,tm,tr,l,r,D-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    ll n2 = (1<<n);
    dp.resize(n2*2);
    a.resize(n2);
    rev.resize(n);
    sw.resize(n);
    for (ll i=0;i<n2;i++) cin >> a[i];
    build(1,0,n2);
    for (ll i=0;i<q;i++)
    {
        ll t;
        cin >> t;
        if (t==1)
        {
            ll p, x;
            cin >> p >> x;
            p--;
            upd(1,0,n2,p,x,n-1);
            continue;
        }
        if (t==2)
        {
            ll x;
            cin >> x;
            x--;
            if (x>=0) rev[x] = 1-rev[x];
            continue;
        }
        if (t==3)
        {
            ll x;
            cin >> x;
            sw[x] = 1-sw[x];
            continue;
        }
        ll l, r;
        cin >> l >> r;
        l--;
        cout << get(1,0,n2,l,r,n-1) << "\n";
    }
}