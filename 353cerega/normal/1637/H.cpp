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

ll t[1200000], del[1200000], t2[1200000];
vector<ll> A;


void build(ll v, ll tl, ll tr)
{
    del[v] = 0;
    if (tl==tr)
    {
        t[v] = A[tl];
        t2[v] = tl;
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    t[v] = max(t[v*2],t[v*2+1]);
    if (t[v*2]>t[v*2+1]) t2[v] = t2[v*2];
    else t2[v] = t2[v*2+1];
}



vector<ll> p;

ll calc(ll L, ll R)
{
    if (L+1==R) return 0;
    ll M = (L+R)/2;
    ll C = calc(L,M)+calc(M,R);
    ll i = L;
    ll j = M;
    vector<ll> a;
    while (i<M or j<R)
    {
        if (i==M or (j!=R and p[j]<p[i]))
        {
            a.push_back(p[j]);
            C += M-i;
            j++;
            continue;
        }
        a.push_back(p[i]);
        i++;
    }
    for (ll q=0;q<R-L;q++) p[q+L] = a[q];
    return C;
}

void push(ll v)
{
    t[v*2] += del[v];
    t[v*2+1] += del[v];
    del[v*2] += del[v];
    del[v*2+1] += del[v];
    del[v] = 0;
}

void upd2(ll v, ll tl, ll tr, ll l, ll r, ll x)
{
    if (l<=tl and tr<=r)
    {
        t[v] += x;
        del[v] += x;
        //if (tl==tr) t2[v] = tl;
        return;
    }
    ll tm = (tl+tr)/2;
    if (del[v]!=0) push(v);
    if (l<=tm) upd2(v*2,tl,tm,l,r,x);
    if (r>tm) upd2(v*2+1,tm+1,tr,l,r,x);
    t[v] = max(t[v*2],t[v*2+1]);
    if (t[v*2]>t[v*2+1]) t2[v] = t2[v*2];
    else t2[v] = t2[v*2+1];
}


void solve()
{
    ll n;
    cin >> n;
    p.clear();
    p.resize(n);
    A.resize(n);
    for (ll i=0;i<n;i++)
    {
        cin >> p[i];
        p[i]--;
        ll x = i-2*p[i];
        A[i] = x;
    }
    ll C = calc(0,n);
    cout << C;
    build(1,0,n-1);
    for (ll z=0;z<n;z++)
    {
        C -= t[1];
        ll w = t2[1];
        upd2(1,0,n-1,w,w,-mod);
        upd2(1,0,n-1,0,n-1,1);
        cout << " " << C;
    }
    cout << "\n";
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