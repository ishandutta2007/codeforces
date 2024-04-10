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




int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> x(n,vector<ll>(3));
    vector<vector<ll>> F(n,vector<ll>(3));
    vector<ll> ok(n);
    ll Q = 0;
    vector<ll> D0(3), D1(3);
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<3;j++)
        {
            cin >> x[i][j];
            if (x[i][j]==0) continue;
            if (x[i][j]>0)
            {
                x[i][j] = 250-x[i][j];
                D0[j]++;
                continue;
            }
            F[i][j] = 1;
            x[i][j] += 250;
            Q++;
            D1[j]++;
            ok[i] = 1;
        }
    }
    ll A = 0;
    if (Q>=90)
    {
        cout << 1 << "\n";
        return 0;
    }
    vector<ll> q(3);
    vector<vector<ll>> vals(3);
    for (ll i=0;i<3;i++)
    {
        for (ll j=0;j<=D1[i];j++)
        {
            ll cur = D1[i]-j+D0[i];
            ll prv = D1[i]-j-1+D0[i];
            if (j==D1[i])
            {
                vals[i].push_back(j);
                continue;
            }
            ll k = cur;
            ll R = 0, R2 = 0;
            while (k<=n and R<12)
            {
                k *= 2;
                R += 2;
            }
            k = prv;
            while (k<=n and R2<12)
            {
                k *= 2;
                R2 += 2;
            }
            R = min(R,12LL);
            R2 = min(R2,12LL);
            if (R!=R2) vals[i].push_back(j);
        }
    }
    for (ll q0: vals[0])
    {
        q[0] = q0;
        for (ll q1: vals[1])
        {
            q[1] = q1;
            for (ll q2: vals[2])
            {
                q[2] = q2;
                ll del = 0;
                ll S = 0;
                vector<ll> C(3);
                for (ll j=0;j<3;j++)
                {
                    S += 100*q[j];
                    ll k = D1[j]-q[j]+D0[j];
                    while (k<=n and C[j]<12)
                    {
                        k *= 2;
                        C[j] += 2;
                    }
                    C[j] = min(C[j],12LL);
                    S += x[0][j]*C[j];
                }
                vector<vector<vector<ll>>> dp(q[0]+2,vector<vector<ll>>(q[1]+2,vector<ll>(q[2]+2)));
                for (ll i=1;i<n;i++)
                {
                    if (ok[i]==0)
                    {
                        ll S2 = 0;
                        for (ll b=0;b<3;b++)
                        {
                            S2 += x[i][b]*C[b];
                        }
                        if (S>=S2) del++;
                        continue;
                    }
                    vector<vector<vector<ll>>> dp2(q[0]+2,vector<vector<ll>>(q[1]+2,vector<ll>(q[2]+2)));
                    for (ll M=0;M<8;M++)
                    {
                        ll S2 = 0;
                        ll B = 0;
                        vector<ll> d(3);
                        for (ll b=0;b<3;b++)
                        {
                            if (M&(1LL<<b))
                            {
                                d[b] = 1;
                                if (F[i][b]==0) B = 1;
                                continue;
                            }
                            S2 += x[i][b]*C[b];
                        }
                        if (B==1) continue;
                        ll W = 0;
                        if (S>=S2) W = 1;
                        for (ll z0=0;z0<=q[0];z0++)
                        {
                            for (ll z1=0;z1<=q[1];z1++)
                            {
                                for (ll z2=0;z2<=q[2];z2++)
                                {
                                    dp2[z0+d[0]][z1+d[1]][z2+d[2]] = max(dp2[z0+d[0]][z1+d[1]][z2+d[2]],dp[z0][z1][z2]+W);
                                }
                            }
                        }
                    }
                    dp = dp2;
                }
                A = max(A,dp[q[0]][q[1]][q[2]]+del);
            }
        }
    }
    cout << n-A << "\n";
}