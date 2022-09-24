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

//    ll w = 1000000LL*1000000LL+1;
//    ll h = 100;
//    vector<vector<ll>> a(h*4,vector<ll>(h*4));
//    for (int i=0;i<h;i++)
//    {
//        for (int j=0;j<h;j++)
//        {
//            int k = 0;
//            if (j>i and j%2!=i%2) k++;
//            int d = 0;
//            if (j==h-1) d = 2;
//            a[i][j+k*h+d*h] = 1;
//            a[i+h][j+(1+k)%2*h+d*h] = 1;
//            a[i+2*h][j+k*h+2*h] = 1;
//            a[i+3*h][j+(1+k)%2*h+2*h] = 1;
//        }
//    }
//    vector<vector<ll>> cur(h*4,vector<ll>(h*4));
//    for (int i=0;i<h*4;i++) cur[i][i] = 1;
//    while (true)
//    {
//        if (w%2==1)
//        {
//            vector<vector<ll>> A(h*4,vector<ll>(h*4));
//            for (int i=0;i<4*h;i++)
//            {
//                for (int j=0;j<4*h;j++)
//                {
//                    for (int k=0;k<4*h;k++)
//                    {
//                        A[i][k] = (A[i][k]+a[i][j]*cur[j][k])%mod;
//                    }
//                }
//            }
//            cur = A;
//        }
//        w /= 2;
//        if (w==0) break;
//        vector<vector<ll>> A(h*4,vector<ll>(h*4));
//        for (int i=0;i<4*h;i++)
//        {
//            for (int j=0;j<4*h;j++)
//            {
//                for (int k=0;k<4*h;k++)
//                {
//                    A[i][k] = (A[i][k]+a[i][j]*a[j][k])%mod;
//                }
//            }
//        }
//        a = A;
//    }
//    cout << cur[h][2*h] << endl;

//1)364553235

//ll cnt[101][101][101];
//cnt[0][0][0] = 1;
//int mx = 100;
//for (int i=1;i<=mx;i++)
//{
//for (int j=0;j<=i;j++)
//{
//for (int k=0;k<=i;k++)
//{
//cnt[i][j][k] = 1;
//if (j>0) cnt[i][j][k] = (cnt[i-1][j-1][k]+cnt[i][j][k])%mod;
//if (k>0) cnt[i][j][k] = (cnt[i-1][j][k-1]+cnt[i][j][k])%mod;
//if (j>0 and k>0) cnt[i][j][k] = (cnt[i-1][j-1][k-1]+cnt[i][j][k])%mod;
//}
//}
//}
//vector<vector<ll>> c(mx+1);
//for (int i=0;i<=mx;i++)
//{
//c[i].resize(i+1);
//c[i][0] = c[i][i] = 1;
//for (int j=1;j<i;j++)
//{
//c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
//}
//}
//vector<vector<ll>> dp(mx+1,vector<ll>(mx+1));
//vector<vector<ll>> dp2(mx+1,vector<ll>(mx+1));
//dp[0][0] = 0;
//dp2[0][0] = 1;
//for (int i=1;i<=mx;i++)
//{
//dp[0][i] = 1;
//dp2[0][i] = 1;
//}
//for (int h=1;h<=mx;h++)
//{
//vector<ll> cur(mx+1);
//for (int S=1;S<=mx;S++)
//{
//cur[S] = cur[S-1];
//for (int L=1;L<=S-1;L++)
//{
//int R = S-L-1;
//for (int h1=0;h1<h and h1<=L;h1++)
//{
//for (int h2=max(0,h-h1);h2<h and h2<=R;h2++)
//{
//cur[S] = (cur[S]+(dp2[L][h1]*dp[R][h2]+dp[L][h1]*dp2[R][h2]-dp[L][h1]*dp[R][h2])%mod*cnt[h-1][h1][h2])%mod;
//if (cur[S]<0) cur[S] += mod;
//}
//}
//for (int h1=0;h1<h and h1<=L;h1++)
//{
//for (int h2=max(1,h-h1+1);h2<=h and h2<=R;h2++)
//{
//cur[S] = (cur[S]+(dp2[L][h1]*dp[R][h2-1]+dp[L][h1]*dp2[R][h2-1]-dp[L][h1]*dp[R][h2-1])%mod*cnt[h-1][h1][h2-1])%mod;
//if (cur[S]<0) cur[S] += mod;
//}
//}
//}
//dp[h][S] = cur[S];
//dp2[h][S] = (dp[h][S]+dp[h-1][S])%mod;
//cur[S] = (cur[S]+dp[h-1][S])%mod;
//}
//}
//ll ans = 0;
//for (int i=0;i<mx;i++)
//{
//ans = (ans+dp[i][mx]*c[mx-1][i])%mod;
//}
//cout << ans << endl;
//ll a = 1, b = 1;
//for (int i=0;i<100;i++)
//{
//a = (a*100)%mod;
//b = (b*99)%mod;
//}
//a += mod-b;
//a %= mod;
//cout << a << endl;

int main()
{
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    k++;
    vector<ll> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    vector<ll> res(n);
    for (ll i=0;i<n;i++)
    {
        res[i] = (i/k)*a[i];
        if (i>0) res[i] += res[i-1];
    }
    ll S = 0;
    ll cur = 0;
    ll INF = mod*mod;
    ll ans = -INF;
    for (ll i=n-1;i>=0;i--)
    {
        ll L = i/k+1;
        ans = max(ans,cur+S*L+res[i]);
        cur += S;
        S += a[i];
    }
    ans = max(ans,cur);
    cout << ans << endl;
}