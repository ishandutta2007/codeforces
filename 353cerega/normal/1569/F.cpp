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


ll n, m, k;
vector<vector<ll>> g;
ll N;
vector<ll> a;
vector<ll> ord;
vector<vector<ll>> col;
vector<ll> b;

void rec2(ll p, ll M)
{
    if (p==N)
    {
        col.push_back(b);
        return;
    }
    for (ll i=0;i<=M;i++)
    {
        b[p] = i;
        if (i==M) rec2(p+1,M+1);
        else rec2(p+1,M);
    }
}

void prec()
{
    b.resize(N,-1);
    rec2(0,0);
}

void check()
{
    ll n2 = (1LL<<N);
    vector<vector<ll>> msk(n2,vector<ll>(N));
    vector<vector<ll>> A(N);
    for (ll i=0;i<n;i++)
    {
        A[a[i]].push_back(i);
    }
    for (ll i=0;i<N;i++)
    {
        if (g[A[i][0]][A[i][1]]==1) msk[(1<<i)][i] = 1;
    }
    for (ll M=1;M<n2;M++)
    {
        for (ll i=0;i<N;i++)
        {
            if (msk[M][i]==0) continue;
            for (ll j=0;j<N;j++)
            {
                if (M&(1LL<<j)) continue;
                if ((g[A[i][0]][A[j][0]]==1 and g[A[i][1]][A[j][1]]==1) or (g[A[i][0]][A[j][1]]==1 and g[A[i][1]][A[j][0]]==1))
                {
                    msk[M+(1LL<<j)][j] = 1;
                }
            }
        }
    }
    ll ok = 0;
    for (ll j=0;j<N;j++)
    {
        if (msk[n2-1][j]==1) ok = 1;
    }
    if (ok==0) return;
    for (ll i=0;i<col.size();i++)
    {
        vector<ll> c = a;
        for (ll j=0;j<n;j++) c[j] = col[i][c[j]];
        ll Q = 0;
        for (ll j=0;j<n;j++)
        {
            Q = Q*7+c[j];
        }
        ord.push_back(Q);
    }
}

void rec(ll p)
{
    if (p==n/2)
    {
        check();
    }
    for (ll i=0;i<n;i++)
    {
        if (a[i]==-1)
        {
            a[i] = p;
            for (ll j=i+1;j<n;j++)
            {
                if (a[j]!=-1) continue;
                a[j] = p;
                rec(p+1);
                a[j] = -1;
            }
            a[i] = -1;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    N = n/2;
    prec();
    g.resize(n,vector<ll>(n));
    a.resize(n,-1);
    for (ll i=0;i<m;i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = g[v][u] = 1;
    }
    rec(0);
    sort(ord.begin(),ord.end());
    vector<ll> C(N);
    for (ll i=0;i<ord.size();i++)
    {
        if (i!=0 and ord[i]==ord[i-1]) continue;
        ll x = ord[i];
        ll M = 0;
        while (x>0)
        {
            M = max(M,x%7);
            x /= 7;
        }
        C[M]++;
    }
    ll A = 0;
    ll R = 1;
    for (ll j=0;j<N;j++)
    {
        R *= k-j;
        A += C[j]*R;
    }
    cout << A << "\n";
}