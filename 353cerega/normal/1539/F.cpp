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

int t[1200000];
int del[1200000];

void build(int v, int tl, int tr)
{
    t[v] = tl;
    del[v] = 0;
    if (tl==tr) return;
    int tm = (tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
}

void push(int v)
{
    t[2*v] += del[v];
    t[2*v+1] += del[v];
    del[2*v] += del[v];
    del[2*v+1] += del[v];
    del[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val)
{
    if (tl==l and tr==r)
    {
        del[v] += val;
        t[v] += val;
        return;
    }
    push(v);
    int tm = (tl+tr)/2;
    if (r<=tm)
    {
        update(2*v,tl,tm,l,r,val);
        t[v] = min(t[2*v],t[2*v+1]);
        return;
    }
    if (l>tm)
    {
        update(2*v+1,tm+1,tr,l,r,val);
        t[v] = min(t[2*v],t[2*v+1]);
        return;
    }
    update(2*v,tl,tm,l,tm,val);
    update(2*v+1,tm+1,tr,tm+1,r,val);
    t[v] = min(t[2*v],t[2*v+1]);
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tl==l and tr==r) return t[v];
    push(v);
    int tm = (tl+tr)/2;
    if (r<=tm) return get(2*v,tl,tm,l,r);
    if (l>tm) return get(2*v+1,tm+1,tr,l,r);
    return min(get(2*v,tl,tm,l,tm),get(2*v+1,tm+1,tr,tm+1,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll,ll>> ord(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        ord[i] = {a[i],i};
    }
    sort(ord.begin(),ord.end());
    vector<vector<int>> dp(4,vector<int>(n));
    build(1,0,n-1);
    for (int i=0;i<n;i++)
    {
        if (i==0 or ord[i].X!=ord[i-1].X)
        {
            for (int j=i;j<n and ord[j].X==ord[i].X;j++)
            {
                int p = ord[j].Y;
                update(1,0,n-1,p,n-1,-2);
            }
        }
        int p = ord[i].Y;
        int c2 = get(1,0,n-1,p,p);
        int c = get(1,0,n-1,p,n-1);
        dp[0][p] = c2-c;
    }
    build(1,0,n-1);
    for (int i=0;i<n;i++)
    {
        if (i==0 or ord[i].X!=ord[i-1].X)
        {
            for (int j=i;j<n and ord[j].X==ord[i].X;j++)
            {
                int p = n-1-ord[j].Y;
                update(1,0,n-1,p,n-1,-2);
            }
        }
        int p = n-1-ord[i].Y;
        int c2 = get(1,0,n-1,p,p);
        int c = get(1,0,n-1,p,n-1);
        dp[1][n-1-p] = c2-c;
    }
    reverse(ord.begin(),ord.end());
    build(1,0,n-1);
    for (int i=0;i<n;i++)
    {
        if (i==0 or ord[i].X!=ord[i-1].X)
        {
            for (int j=i;j<n and ord[j].X==ord[i].X;j++)
            {
                int p = ord[j].Y;
                update(1,0,n-1,p,n-1,-2);
            }
        }
        int p = ord[i].Y;
        int c2 = get(1,0,n-1,p,p);
        int c = get(1,0,n-1,p,n-1);
        dp[2][p] = c2-c;
    }
    build(1,0,n-1);
    for (int i=0;i<n;i++)
    {
        if (i==0 or ord[i].X!=ord[i-1].X)
        {
            for (int j=i;j<n and ord[j].X==ord[i].X;j++)
            {
                int p = n-1-ord[j].Y;
                update(1,0,n-1,p,n-1,-2);
            }
        }
        int p = n-1-ord[i].Y;
        int c2 = get(1,0,n-1,p,p);
        int c = get(1,0,n-1,p,n-1);
        dp[3][n-1-p] = c2-c;
    }
    for (int i=0;i<n;i++)
    {
        cout << max((dp[3][i]+dp[2][i]+1)/2,(dp[0][i]+dp[1][i])/2) << " ";
    }
}