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


vector<vector<ll>> x(3,vector<ll>(2));

ld calc4(ld x0, ld y0, ld x1, ld y1, ll p)
{
    ld S = sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
    for (ll i=0;i<3;i++)
    {
        if (i==p) continue;
        S += sqrt((x[i][0]-x1)*(x[i][0]-x1)+(x[i][1]-y1)*(x[i][1]-y1));
    }
    return S;
}

ld calc3(ld x0, ld y0, ld x1, ll p)
{
    ld mn = mod*mod;
    ld Ly1 = -10000;
    ld Ry1 = 10000;
    for (ll z=0;z<40;z++)
    {
        ld y11 = (Ly1*2+Ry1)/3;
        ld val0 = calc4(x0,y0,x1,y11,p);
        ld y12 = (Ly1+Ry1*2)/3;
        ld val1 = calc4(x0,y0,x1,y12,p);
        mn = min(mn,min(val0,val1));
        if (val0<val1) Ry1 = y12;
        else Ly1 = y11;
    }
    return mn;
}

ld calc2(ld x0, ld y0, ll p)
{
    ld mn = mod*mod;
    ld Lx1 = -10000;
    ld Rx1 = 10000;
    for (ll z=0;z<40;z++)
    {
        ld x11 = (Lx1*2+Rx1)/3;
        ld val0 = calc3(x0,y0,x11,p);
        ld x12 = (Lx1+Rx1*2)/3;
        ld val1 = calc3(x0,y0,x12,p);
        mn = min(mn,min(val0,val1));
        if (val0<val1) Rx1 = x12;
        else Lx1 = x11;
    }
    return mn;
}

ld calc(ld x0)
{
    ld mn = mod*mod;
    ld Ly0 = -10000;
    ld Ry0 = 10000;
    for (ll z=0;z<40;z++)
    {
        ld y01 = (Ly0*2+Ry0)/3;
        ld val0 = 0;
        for (ll j=0;j<3;j++)
        {
            val0 = max(val0,calc2(x0,y01,j));
        }
        ld y02 = (Ly0+Ry0*2)/3;
        ld val1 = 0;
        for (ll j=0;j<3;j++)
        {
            val1 = max(val1,calc2(x0,y02,j));
        }
        mn = min(mn,min(val0,val1));
        if (val0<val1) Ry0 = y02;
        else Ly0 = y01;
    }
    return mn;
}

void solve()
{
    for (ll i=0;i<3;i++) cin >> x[i][0] >> x[i][1];
    ld Lx0 = -10000;
    ld Rx0 = 10000;
    ld A = mod*mod;
    for (ll z=0;z<40;z++)
    {
        ld x01 = (Lx0*2+Rx0)/3;
        ld val0 = calc(x01);
        ld x02 = (Lx0+Rx0*2)/3;
        ld val1 = calc(x02);
        A = min(A,min(val0,val1));
        if (val0<val1) Rx0 = x02;
        else Lx0 = x01;
    }
    cout.precision(20);
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    //cin >> T;
    T = 1;
    while (T--) solve();
}