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

const int root = 390359979;
const int root_1 = 304321983;
const int root_pw = 1<<20;


void fft (vector<ll> & a, bool invert) {
    int n = (int) a.size();
    ll r = root;
    ll r2 = root_1;
    ll C = root_pw;
    while (n<C)
    {
        r = r*r%mod;
        r2 = r2*r2%mod;
        C /= 2;
    }
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? r2 : r;
        for (int i=len; i<C; i<<=1)
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
}

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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i=1;i<n;i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<ll>> A(n);
    for (ll i=0;i<n;i++)
    {
        ll C = g[i].size();
        if (i>0) C--;
        A[i] = {1,C};
    }
    for (ll j=1;A.size()>1;j++)
    {
        ll sz = A.size();
        for (ll i=0;i<sz;i++) A[i].resize((1<<j)*2);
        vector<vector<ll>> B;

        for (ll i=0;i<sz;i+=2)
        {
            if (i+1==sz)
            {
                B.push_back(A[i]);
                break;
            }
            fft(A[i],false);
            fft(A[i+1],false);
            for (ll z=0;z<A[i].size();z++) A[i][z] = (A[i][z]*A[i+1][z])%mod;
            fft(A[i],true);
            B.push_back(A[i]);
        }
        A = B;
    }
    ll ans = 0;
    A[0].resize(n+1);
    vector<ll> F(n+1);
    F[0] = 1;
    for (ll i=1;i<=n;i++) F[i] = F[i-1]*i%mod;
    for (ll i=0;i<=n;i++)
    {
        ll S = 1;
        if (i%2==1) S = -1;
        ans += S*F[n-i]*A[0][i]%mod;
    }
    ans %= mod;
    if (ans<0) ans += mod;
    cout << ans << endl;
}