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


const ll mx = 6000000;
int nxt[mx][2];
int c[mx];
vector<ll> p;
ll S = 1;

void add(ll x)
{
    ll u = 0;
    c[u]++;
    for (ll b=29;b>=0;b--)
    {
        ll q = 0;
        if (x&(1LL<<b)) q = 1;
        if (nxt[u][q]==-1)
        {
            nxt[u][q] = S++;
        }
        u = nxt[u][q];
        c[u]++;
    }
}

ll calc2(ll u, ll u2, ll b, ll x)
{
    if (b==-1) return (p[c[u]]-1)*(p[c[u2]]-1)%mod;
    if (x&(1LL<<b))
    {
        vector<ll> Q(2);
        ll A = 0;
        for (ll z=0;z<2;z++)
        {
            if (nxt[u][z]==-1 or nxt[u2][1-z]==-1)
            {
                Q[z] = 0;
                continue;
            }
            Q[z] = calc2(nxt[u][z],nxt[u2][1-z],b-1,x);
            ll W = 0;
            if (nxt[u][1-z]!=-1) W += c[nxt[u][1-z]];
            if (nxt[u2][z]!=-1) W += c[nxt[u2][z]];
            A += p[W]*Q[z];
        }
        A -= Q[0]*Q[1];
        A %= mod;
        if (A<0) A += mod;
        return A;
    }
    else
    {
        vector<ll> Q(2);
        ll A = 0;
        vector<ll> W(4);
        for (ll z=0;z<2;z++)
        {
            if (nxt[u][z]!=-1) W[z] = c[nxt[u][z]];
            if (nxt[u2][z]!=-1) W[z+2] = c[nxt[u2][z]];
            if (nxt[u][z]==-1 or nxt[u2][z]==-1)
            {
                Q[z] = 0;
                continue;
            }
            Q[z] = calc2(nxt[u][z],nxt[u2][z],b-1,x);
            A += Q[z];
        }
        ll P = 1;
        for (ll j=0;j<4;j++)
        {
            P = (P*(p[W[j]]-1))%mod;
        }
        A -= P;
        P = 1;
        for (ll j=0;j<2;j++)
        {
            P = (P*(p[W[j]]-1))%mod;
        }
        P = (P*(p[W[2]+W[3]]-1));
        A += P;
        P = 1;
        for (ll j=2;j<4;j++)
        {
            P = (P*(p[W[j]]-1))%mod;
        }
        P = (P*(p[W[0]+W[1]]-1));
        A += P;
        A += (p[W[0]]-1)*(p[W[3]]-1);
        A += (p[W[1]]-1)*(p[W[2]]-1);
        A %= mod;
        if (A<0) A += mod;
        return A;
    }
}

ll calc(ll u, ll b, ll x)
{
    if (b==-1) return p[c[u]];
    if (x&(1LL<<b))
    {
        if (nxt[u][0]==-1 or nxt[u][1]==-1)
        {
            return p[c[u]]-1;
        }
        return (p[c[u]]-1+mod-calc2(nxt[u][0],nxt[u][1],b-1,x))%mod;
    }
    ll Q = 0;
    for (ll z=0;z<2;z++)
    {
        if (nxt[u][z]==-1) continue;
        Q += calc(nxt[u][z],b-1,x);
    }
    Q %= mod;
    return Q;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    for (ll i=0;i<mx;i++)
    {
        c[i] = 0;
        nxt[i][0] = nxt[i][1] = -1;
    }
    x++;
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    p.resize(n+1);
    p[0] = 1;
    for (ll i=1;i<=n;i++) p[i] = p[i-1]*2%mod;
    sort(a.begin(),a.end());
    for (ll i=0;i<n;i++) add(a[i]);
    if (x==(1LL<<30))
    {
        cout << p[n]-1 << "\n";
        return;
    }
    cout << calc(0,29,x) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    while (T--)
    {
        solve();
    }
}