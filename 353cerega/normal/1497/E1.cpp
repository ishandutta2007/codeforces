#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define X first
#define Y second

const ll mod = 1000000007;

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

//ll t[1200000];
//ll del[1200000];

/*void build(int n)
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

/*void update (int v, int tl, int tr, int l, int r, ll val) {
    if (tl>=l and tr<=r)
    {
        del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //if (del[v]!=0) push(v);
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
    t[v] = t[2*v]+t[2*v+1];
}*/


/*pair<ll,ll> get (int v, int tl, int tr, int p) {
    if (tl==tr) return t[v];
    int tm = (tl+tr)/2;
    //push(v);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/



int main()
{
    ios_base::sync_with_stdio(false);
    ll mx = 10000000;
    vector<ll> d(mx+1), pr;
    for (ll i=2;i<=mx;i++)
    {
        if (d[i]==0)
        {
            d[i] = i;
            pr.push_back(i);
        }
        for (int j=0;j<pr.size() and pr[j]<=d[i] and i*pr[j]<=mx;j++)
        {
            d[pr[j]*i] = pr[j];
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll,ll> num;
        ll sz = 0;
        for (ll i=0;i<n;i++)
        {
            ll q;
            cin >> q;
            ll v = 1;
            while (q>1)
            {
                ll p = d[q];
                q /= p;
                if (d[q]==p) q /= p;
                else v *= p;
            }
            if (num.count(v)==0)
            {
                num[v] = sz;
                sz++;
            }
            a[i] = num[v];
        }
        vector<pair<ll,ll>> ord(n);
        for (ll i=0;i<n;i++)
        {
            ord[i] = {a[i],i};
        }
        sort(ord.begin(),ord.end());
        vector<ll> nxt(n,n);
        for (ll i=0;i<n;i++)
        {
            if (i+1<n and ord[i].X==ord[i+1].X)
            {
                nxt[ord[i].Y] = ord[i+1].Y;
            }
        }
        vector<vector<ll>> kek(n,vector<ll>(k+1));
        vector<ll> mn(k+1,n);
        for (ll i=n-1;i>=0;i--)
        {
            if (mn[k]>nxt[i]) mn[k] = nxt[i];
            for (int j=k-1;j>=0;j--)
            {
                if (mn[j]>mn[j+1]) swap(mn[j],mn[j+1]);
                else break;
            }
            kek[i] = mn;
        }
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,n+1));
        dp[0][0] = 0;
        for (ll i=0;i<n;i++)
        {
            for (ll j=0;j<=k;j++)
            {
                for (ll r=0;r+j<=k;r++)
                {
                    dp[kek[i][r]][j+r] = min(dp[kek[i][r]][j+r],dp[i][j]+1);
                }
            }
        }
        cout << dp[n][k] << "\n";
    }
}