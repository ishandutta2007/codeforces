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


void solve()
{
    ll n;
    cin >> n;
    vector<vector<pair<ll,ll>>> a(3), a2(3);
    n /= 3;
    for (ll i=0;i<3*n;i++)
    {
        ll x, y, p;
        cin >> x >> y >> p;
        p--;
        a[p].push_back({x,y});
        a2[p].push_back({y,x});
    }
    ll k = 0;
    for (ll i=0;i<4;i++)
    {
        for (ll j=0;j<3;j++)
        {
            sort(a[j].begin(),a[j].end());
            sort(a2[j].begin(),a2[j].end());
        }
        for (ll j=0;j<3;j++)
        {
            ll L = 0, R = n+1;
            while (R-L>1)
            {
                ll M = (L+R)/2;
                ll x = a[j][M-1].X;
                vector<vector<ll>> A(3);
                for (ll z=0;z<3;z++)
                {
                    if (j==z) continue;
                    for (ll p=0;p<n;p++)
                    {
                        if (a2[z][p].Y>x)
                        {
                            A[z].push_back(a2[z][p].X);
                        }
                    }
                }
                ll ok = 0;
                for (ll b=0;b<3;b++)
                {
                    for (ll b2=0;b2<3;b2++)
                    {
                        if (b==b2) continue;
                        if (A[b].size()<M or A[b2].size()<M) continue;
                        ll sz = A[b2].size();
                        if (A[b][M-1]<A[b2][sz-M]) ok = 1;
                    }
                }
                if (ok==1) L = M;
                else R = M;
            }
            k = max(k,L);
        }
        for (ll j=0;j<3;j++)
        {
            ll L = 0, R = n+1;
            while (R-L>1)
            {
                ll M = (L+R)/2;
                ll x = a[j][M-1].X;
                ll ok = 0;
                for (ll j2=0;j2<3;j2++)
                {
                    if (j2==j) continue;
                    ll x2 = a[j2][n-M].X;
                    ll j3 = 3-j-j2;
                    ll C = 0;
                    for (ll z=0;z<n;z++)
                    {
                        if (x<a[j3][z].X and x2>a[j3][z].X) C++;
                    }
                    if (C>=M) ok = 1;
                }
                if (ok==1) L = M;
                else R = M;
            }
            k = max(k,L);
        }
        if (i%2==0)
        {
            for (ll j=0;j<3;j++)
            {
                for (ll p=0;p<n;p++)
                {
                    a[j][p].X *= -1;
                    a2[j][p].Y *= -1;
                }
            }
        }
        else
        {
            for (ll j=0;j<3;j++)
            {
                for (ll p=0;p<n;p++)
                {
                    swap(a[j][p].X,a[j][p].Y);
                    swap(a2[j][p].X,a2[j][p].Y);
                }
            }
        }
    }
    cout << k*3 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll t = 1;
    while (t--)
    {
        solve();
    }
}