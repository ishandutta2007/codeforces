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




void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (ll i=0;i<n;i++) cin >> s[i];
    ll A = mod;
    vector<vector<ll>> pr(n+1,vector<ll>(m));
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<m;j++)
        {
            pr[i+1][j] = pr[i][j];
            if (s[i][j]=='1') pr[i+1][j]++;
        }
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=i+4;j<n;j++)
        {
            ll mn = mod;
            ll S = 0;
            ll L = (j-i-1);
            ll S2 = 0;
            for (ll p=0;p<m;p++)
            {
                S += L-pr[j][p]+pr[i+1][p];
                if (p>0)
                {
                    if (s[i][p-1]=='0') S++;
                    if (s[j][p-1]=='0') S++;
                }
                ll p2 = p-3;
                if (p2>=0)
                {
                    if (s[i][p2]=='0') S2--;
                    if (s[j][p2]=='0') S2--;
                    ll D = pr[j][p2]-pr[i+1][p2];
                    S2 -= D;
                    S2 += (L-D);
                    mn = min(mn,S2);
                    S2 -= (L-D);
                }
                A = min(A,S+mn);
                S -= L-pr[j][p]+pr[i+1][p];
                S += pr[j][p]-pr[i+1][p];
            }
        }
    }
    cout << A << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    //T = 1;
    while (T--) solve();
}