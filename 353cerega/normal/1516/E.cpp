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

/*void build()
{
    for (int i=0;i<1200000;i++)
    {
        t[i] = 0;
        //del[i] = 0;
    }
}*/

/*void push(int v, int tl, int tr, int tm)
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
        //del[v] += val;
        t[v] += val;
        return;
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
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
    //t[v] = min(t[2*v],t[2*v+1]);
}


ll get (int v, int tl, int tr, int p) {
    //if (del[v]!=0 and tl!=tr) push(v,tl,tr,tm);
    if (tl==tr)
    {
        return t[v];
    }
    int tm = (tl+tr)/2;
    //push(v,tl,tr,tm);
    if (p<=tm) return t[v]+get(2*v,tl,tm,p);
    else return t[v]+get(2*v+1,tm+1,tr,p);
}*/




int main()
{
    ios_base::sync_with_stdio(false);
    /*ll ans = 0;
    ll n = 2;
    vector<ll> dp1(n+1), dp2(n+1);
    for (int i=1;i<=n;i++)
    {
        int d = i-1;
        dp1[i] = (n-d)*(n+1-d)/2;
        if (d<n/2) dp2[i] = (n-2*d)*(n-2*d-1)/2;
    }
    for (int i=1;i<=n;i++)
    {
        ans += dp1[i]+dp2[i];
        //if (i*2<=n) ans += dp1[i*2]*6;
        //if (i*2<=n) ans += dp1[i*2]*6;
        ans += 15*(dp1[i]+dp2[i]);
    }
    cout << ans << endl;*/
    ll n, k;
    cin >> n >> k;
    vector<ll> f(k*2+1), fn(k*2+1), obr(k*2+1), obrf(k*2+1), obrfn(2*k+1);
    f[0] = 1;
    fn[0] = 1;
    obrf[0] = 1;
    obrfn[0] = 1;
    for (ll i=1;i<=k*2;i++)
    {
        f[i] = f[i-1]*i%mod;
        fn[i] = fn[i-1]*(n+1-i)%mod;
        if (fn[i]!=0) obrfn[i] = pew(fn[i],mod-2);
        obr[i] = pew(i,mod-2);
        obrf[i] = obrf[i-1]*obr[i]%mod;
    }
    vector<vector<ll>> dp(k+1,vector<ll>(2*k+1));
    dp[0][0] = 1;
    for (int d=0;d<k;d++)
    {
        for (int s=2*d;s<=d+k;s++)
        {
            for (int L=2;L+s<=d+1+k and L+s<=n;L++)
            {
                dp[d+1][s+L] = (dp[d+1][s+L]+dp[d][s]*obr[L]%mod*fn[L+s]%mod*obrfn[s])%mod;
            }
        }
    }
    vector<ll> ans(k+1);
    for (int i=0;i<=k;i++)
    {
        for (int d=0;d<=k;d++)
        {
            ans[i] = (ans[i]+dp[d][d+i]*obrf[d])%mod;
        }
    }
    for (int i=1;i<=k;i++)
    {
        if (i>1) ans[i] = (ans[i]+ans[i-2])%mod;
        cout << ans[i] << " ";
    }
}