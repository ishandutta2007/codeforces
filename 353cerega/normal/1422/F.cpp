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



const ll M = 300;
vector<vector<pair<ll,ll>>> nxt;
vector<vector<pair<ll,ll>>> prv;

vector<vector<ll>> P;

ll get(ll L, ll R)
{
    ll x = 1;
    if (L/M==R/M)
    {
        for (ll i=L;i<=R;i++)
        {
            for (ll z=0;z<prv[i].size();z++)
            {
                if (prv[i][z].X<L) x = x*prv[i][z].Y%mod;
            }
        }
        return x;
    }
    ll s = L/M+1;
    x = P[s][R];
    for (ll i=L;i<s*M;i++)
    {
        for (ll z=0;z<nxt[i].size();z++)
        {
            if (nxt[i][z].X>R) x = x*nxt[i][z].Y%mod;
        }
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll mx = 200000;
    vector<ll> d(mx+1), pr;
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            pr.push_back(i);
        }
        for (ll j=0;j<pr.size() and pr[j]<=d[i] and pr[j]*i<=mx;j++)
        {
            d[i*pr[j]] = pr[j];
        }
    }
    vector<vector<ll>> p(mx+1);
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]!=i) continue;
        ll k = 0;
        ll x = 1;
        while (x*i<=mx)
        {
            x *= i;
            k++;
        }
        p[i].resize(k,-1);
    }
    ll n;
    cin >> n;
    vector<ll> a(n);
    nxt.resize(n);
    prv.resize(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
        ll x = a[i];
        vector<pair<ll,ll>> q;
        while (x>1)
        {
            ll r = d[x];
            if (q.size()>0 and q.back().X==r) q.back().Y++;
            else q.push_back({r,0});
            x /= r;
        }
        for (ll j=0;j<q.size();j++)
        {
            for (ll z=0;z<=q[j].Y;z++)
            {
                if (p[q[j].X][z]!=-1)
                {
                    ll w = p[q[j].X][z];
                    nxt[w].push_back({i,q[j].X});
                    prv[i].push_back({w,q[j].X});
                }
                else
                {
                    prv[i].push_back({-1,q[j].X});
                }
                p[q[j].X][z] = i;
            }
        }
    }
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]!=i) continue;
        for (ll j=0;j<p[i].size();j++)
        {
            if (p[i][j]==-1) continue;
            nxt[p[i][j]].push_back({n,i});
        }
    }
    P.resize(n/M+1,vector<ll>(n+1));
    for (ll s=0;s*M<n;s++)
    {
        ll x = 1;
        ll st = s*M;
        for (ll j=s*M;j<n;j++)
        {
            for (ll z=0;z<prv[j].size();z++)
            {
                if (prv[j][z].X<st) x = x*prv[j][z].Y%mod;
            }
            P[s][j] = x;
        }
    }
    ll q;
    cin >> q;
    ll W = 0;
    while (q--)
    {
        ll L, R;
        cin >> L >> R;
        L = (L+W)%n;
        R = (R+W)%n;
        if (L>R) swap(L,R);
        W = get(L,R);
        cout << W << "\n";
    }
}