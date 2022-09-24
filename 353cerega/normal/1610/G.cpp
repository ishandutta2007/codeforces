#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
const ll mod2 = 998244353;

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

ll mx = 400000;
ll K = 20;
vector<vector<pair<ll,ll>>> up(K,vector<pair<ll,ll>>(mx));
vector<ll> h(mx);
vector<vector<ll>> nxt(mx,vector<ll>(2,-1));
vector<vector<ll>> bck(K,vector<ll>(mx));
vector<ll> lst(mx,-1);
ll S = 1;
ll b = 29;
ll b2 = 41;
vector<ll> p(mx), p2(mx);

ll add(ll u, ll c)
{
    if (nxt[u][c]!=-1) return nxt[u][c];
    ll x = S;
    S++;
    nxt[u][c] = x;
    bck[0][x] = u;
    lst[x] = c;
    h[x] = h[u]+1;
    up[0][x] = {c,c};
    for (ll j=1;(1<<j)<=h[x];j++)
    {
        bck[j][x] = bck[j-1][bck[j-1][x]];
        up[j][x].X = (up[j-1][x].X*p[(1<<(j-1))]+up[j-1][bck[j-1][x]].X)%mod;
        up[j][x].Y = (up[j-1][x].Y*p2[(1<<(j-1))]+up[j-1][bck[j-1][x]].Y)%mod2;
    }
    return x;
}

ll get(ll u, ll v)
{
    ll x = u, y = v;
    for (ll j=K-1;j>=0;j--)
    {
        if (h[x]<(1<<j) or h[y]<(1<<j)) continue;
        if (up[j][x]==up[j][y])
        {
            x = bck[j][x];
            y = bck[j][y];
        }
    }
    if (h[x]==0) return u;
    if (h[y]==0) return v;
    if (lst[x]==0) return u;
    else return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    p.resize(mx);
    p2.resize(mx);
    p[0] = 1;
    p2[0] = 1;
    for (ll j=1;j<mx;j++)
    {
        p[j] = p[j-1]*b%mod;
        p2[j] = p2[j-1]*b2%mod2;
    }
    ll n = s.length();
    vector<ll> pos(n+1);
    ll B = mx;
    vector<ll> prv(mx*2,-1);
    pos[n] = 0;
    prv[B] = 0;
    for (ll i=n-1;i>=0;i--)
    {
        if (s[i]==')')
        {
            B++;
            prv[B] = i;
            pos[i] = add(pos[i+1],1);
            continue;
        }
        B--;
        ll z = prv[B];
        prv[B] = i;
        if (z==-1)
        {
            pos[i] = add(pos[i+1],0);
            continue;
        }
        if (h[pos[z]]==0)
        {
            pos[i] = pos[z];
            continue;
        }
        if (lst[pos[z]]==1)
        {
            pos[i] = add(pos[i+1],0);
            continue;
        }
        ll Q1 = pos[i+1];
        ll Q2 = bck[0][pos[z]];
        Q1 = get(Q1,Q2);
        pos[i] = add(Q1,0);
    }
    ll P = pos[0];
    while (P!=0)
    {
        ll z = lst[P];
        if (z==0) cout << "(";
        else cout << ")";
        P = bck[0][P];
    }
}