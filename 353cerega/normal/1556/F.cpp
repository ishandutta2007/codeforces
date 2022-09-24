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
const int root = 31;
const int MOD = 469762049;
const int root_1 = 15658735;
const int root_pw = 1<<26;*/


/*void fft (vector<int> & a, bool invert) {
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


int parent[600001];
int rnk[600001];

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
}

//ll t[3200000];
//ll del[1200000];

/*
void build(int n)
{
    for (int i=0;i<=4*n;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v)
{
    t[2*v].X += del[v];
    t[2*v+1].X += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}*/

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        //del[v] += val;

        //t[v] += val*(tr-tl+1);
        return;
    }
    int tm = (tl + tr) / 2;
    //if (del[v]!=0) push(v,tl,tr,tm);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = t[2*v]+t[2*v+1];
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}*/

/*
void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl==l and tr==r)
    {
        t[v] = (t[v]+val)%mod;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
}

ll get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);

}
*/


void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> p(n,vector<ll>(n));
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (ll i=0;i<n;i++)
    {
        for (ll j=0;j<n;j++)
        {
            p[i][j] = pew(a[i]+a[j],mod-2);
            p[j][i] = p[i][j];
            p[i][j] = p[i][j]*a[i]%mod;
            p[j][i] = p[j][i]*a[j]%mod;
        }
    }
    ll n2 = (1<<n);
    vector<ll> dp(n2);
    vector<ll> cnt(n2);
    for (ll msk=1;msk<n2;msk++)
    {
        dp[msk] = 1;
        for (ll b=0;b<n;b++)
        {
            if (msk&(1<<b))
            {
                cnt[msk]++;
                for (ll b2=0;b2<n;b2++)
                {
                    if (msk&(1<<b2)) continue;
                    dp[msk] = dp[msk]*p[b][b2]%mod;
                }
            }
        }
    }
    ll ans = 0;
    vector<vector<ll>> kek(n,vector<ll>(n2));
    for (ll i=0;i<n;i++)
    {
        for (ll msk=0;msk<n2;msk++)
        {
            kek[i][msk] = 1;
            for (ll b=0;b<n;b++)
            {
                if (msk&(1<<b))
                {
                    kek[i][msk] = (kek[i][msk]*p[i][b])%mod;
                }
            }
        }
    }
    for (ll msk=1;msk<n2;msk++)
    {
        ll prv = msk;
        while (prv>0)
        {
            prv = (prv-1)&msk;
            ll lft = msk-prv;
            ll R = (n2-1-msk);
            ll q = dp[prv];
            for (ll b=0;b<n;b++)
            {
                if (lft&(1<<b)) q = q*kek[b][R]%mod;
            }
            dp[msk] = dp[msk]-q;
            if (dp[msk]<0) dp[msk] += mod;
        }
        ans = (ans+dp[msk]*cnt[msk])%mod;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
}