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

const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1<<23;


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
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i].X;
        a[i].Y = 1;
    }
    sort(a.begin(),a.end());
    {
        vector<pair<ll,ll>> a2;
        for (ll i=0;i<a.size();i++)
        {
            if (a2.size()>0 and a2.back().X==a[i].X) a2.back().Y += a[i].Y;
            else a2.push_back(a[i]);
        }
        a = a2;
    }
    ll mx = 610000;
    vector<ll> f(mx+1), f2(mx+1), p2(mx+1);
    f[0] = f2[0] = p2[0] = 1;
    for (ll i=1;i<=mx;i++)
    {
        f[i] = f[i-1]*i%mod;
        f2[i] = pew(f[i],mod-2);
        p2[i] = p2[i-1]*2%mod;
    }
    vector<ll> A(mx);
    for (ll w=0;w<k;w++)
    {
        ll x;
        cin >> x;
        ll C = 0, C2 = 0;
        vector<vector<int>> Q(2,vector<int>(1<<19));
        for (ll i=0;i<a.size();i++)
        {
            if (x<=a[i].X) continue;
            if (a[i].Y==1) C2++;
            if (a[i].Y>1)
            {
                C += 2;
            }
        }
        for (ll i=0;i<=C;i++)
        {
            Q[0][i] = f[C]*f2[i]%mod*f2[C-i]%mod;
        }
        for (ll i=0;i<=C2;i++)
        {
            Q[1][i] = f[C2]*f2[i]%mod*f2[C2-i]%mod*p2[i]%mod;
        }
        fft(Q[0],false);
        fft(Q[1],false);
        for (ll z=0;z<Q[0].size();z++)
        {
            Q[0][z] = (Q[0][z]*1LL*Q[1][z])%mod;
        }
        fft(Q[0],true);
        for (ll i=0;i<Q[0].size();i++)
        {
            if (Q[0][i]>0) A[i+x+1] = (A[i+x+1]+Q[0][i])%mod;
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        x /= 2;
        cout << A[x] << "\n";
    }
}