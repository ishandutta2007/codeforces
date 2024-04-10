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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    if (n==1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<string> s(n);
    for (ll i=0;i<n;i++)
    {
        cin >> s[i];
    }
    ll L = s[0].length();
    ll L2 = (1LL<<L);
    vector<vector<ll>> c(L+1,vector<ll>(L+1));
    for (ll i=0;i<=L;i++)
    {
        c[i][i] = c[i][0] = 1;
        for (ll j=1;j<i;j++)
        {
            c[i][j] = (c[i-1][j-1]+c[i-1][j]);
        }
    }
    ld A = 0;
    vector<ll> dp(L2);
    for (ll i=0;i<n;i++)
    {
        dp[0] |= (1LL<<i);
        for (ll j=0;j<n;j++)
        {
            if (i==j) continue;
            ll M = 0;
            for (ll b=0;b<L;b++)
            {
                if (s[i][b]==s[j][b]) M += (1LL<<b);
            }
            dp[M] |= (1LL<<i);
        }
    }
    for (ll m=L2-1;m>=0;m--)
    {
        ll C = 0;
        for (ll b=0;b<L;b++)
        {
            if (m&(1LL<<b))
            {
                C++;
                continue;
            }
            dp[m] |= dp[m+(1LL<<b)];
        }
        ll C2 = 0;
        for (ll i=0;i<n;i++)
        {
            if (dp[m]&(1LL<<i)) C2++;
        }
        A += C2*1.0L/n/c[L][C];
    }
    cout.precision(20);
    cout << A << endl;
}