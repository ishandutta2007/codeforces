#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
//const ll mod = 998244353;
const ll mod = 1000000009;

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
    sz[v] = 1;
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



vector<vector<ll>> nxt;
vector<ll> pr, a;

ll t[1200000], x0[1200000], x1[1200000];

void build(ll v, ll tl, ll tr)
{
    x0[v] = x1[v] = 0;
    if (tl==tr)
    {
        t[v] = a[tl];
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    t[v] = (t[2*v]+t[2*v+1])%mod;
}

void push(ll v, ll tl, ll tr, ll tm)
{
    ll L1 = tm-tl+1, L2 = tr-tm;
    x0[2*v] = (x0[2*v]+x0[v])%mod;
    t[2*v] = (t[2*v]+pr[L1]*x0[v])%mod;
    x1[2*v] = (x1[2*v]+x1[v])%mod;
    t[2*v] = (t[2*v]+pr[L1-1]*x1[v])%mod;
    ll D = (x0[v]*nxt[L1][0]+x1[v]*nxt[L1-1][0])%mod;
    x0[2*v+1] = (x0[2*v+1]+D)%mod;
    t[2*v+1] = (t[2*v+1]+D*pr[L2])%mod;
    {
        D = (x0[v]*nxt[L1-1][0]+x1[v]*nxt[L1-1][1])%mod;
        x1[2*v+1] = (x1[2*v+1]+D)%mod;
        t[2*v+1] = (t[2*v+1]+D*pr[L2-1])%mod;
    }
    x0[v] = x1[v] = 0;
}

void upd(ll v, ll tl, ll tr, ll p, ll D0, ll D1)
{
    if (tl==tr)
    {
        t[v] = (t[v]+D0)%mod;
        return;
    }
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    if (p>tm)
    {
        upd(v*2+1,tm+1,tr,p,D0,D1);
        t[v] = (t[2*v]+t[2*v+1])%mod;
        return;
    }
    ll L1 = (tm-p+1), L2 = (tr-tm);
    ll D = (D0*nxt[L1][0]+D1*nxt[L1-1][0])%mod;
    x0[2*v+1] = (x0[2*v+1]+D)%mod;
    t[2*v+1] = (t[2*v+1]+D*pr[L2])%mod;
    {
        D = (D0*nxt[L1-1][0]+D1*nxt[L1-1][1])%mod;
        x1[2*v+1] = (x1[2*v+1]+D)%mod;
        t[2*v+1] = (t[2*v+1]+D*pr[L2-1])%mod;
    }
    upd(v*2,tl,tm,p,D0,D1);
    t[v] = (t[2*v]+t[2*v+1])%mod;
}

ll get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (tl>=l and tr<=r) return t[v]%mod;
    ll tm = (tl+tr)/2;
    push(v,tl,tr,tm);
    ll A = 0;
    if (tm>=l) A += get(v*2,tl,tm,l,r);
    if (tm<r) A += get(v*2+1,tm+1,tr,l,r);
    return A%mod;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll N = n+1;
    nxt.resize(N+2,vector<ll>(2));
    pr.resize(N+2);
    nxt[0][0] = 1;
    nxt[0][1] = 0;
    pr[0] = 0;
    for (ll i=1;i<=N+1;i++)
    {
        nxt[i][0] = (nxt[i-1][0]+nxt[i-1][1])%mod;
        nxt[i][1] = nxt[i-1][0];
        pr[i] = (pr[i-1]+nxt[i-1][0])%mod;
    }
    a.resize(n+2);
    for (ll i=0;i<n;i++) cin >> a[i];
    build(1,0,N);
    for (ll i=0;i<m;i++)
    {
        ll T, L, R;
        cin >> T >> L >> R;
        L--, R--;
        if (T==2)
        {
            cout << get(1,0,N,L,R) << endl;
            continue;
        }
        upd(1,0,N,L,1,0);
        ll len = R-L+1;
        upd(1,0,N,R+1,mod-nxt[len][0],mod-nxt[len-1][0]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin.tie(0);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}