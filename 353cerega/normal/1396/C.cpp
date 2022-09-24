#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define X first
#define Y second

ll mod = 998244353;

ll gcd(ll a, ll b)
{
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

/*ll mul(ll a, ll b)
{
    return a*b%mod;
}*/
ll mul(ll a, ll b)
{
    return a*b%mod;
}

ll pew(ll a, ll b)
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

/*
typedef complex<double> base;
long double PI = acos(-1);
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (n == 1)  return;

    vector<base> a0 (n/2),  a1 (n/2);
    for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);

    double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1),  wn (cos(ang), sin(ang));
    for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2,  a[i+n/2] /= 2;
        w *= wn;
    }
}
*/
int parent[100001];
int rnk[100001];

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
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}

/*
ll t[20000001];

void build()
{
    for (int i=0;i<2000000;i++)
    {
        t[i] = 0;
    }
}

void update (int num, int v, int tl, int tr, int pos, ll add) {
    t[v+num*(1<<13)] += add;
    if (tl==tr) return;
    int tm = (tl + tr) / 2;
    if (tm>=pos)
    {
        update(num, v * 2, tl, tm, pos, add);
    } else
    {
        update (num, v*2+1, tm+1, tr, pos, add);
    }
}

ll get (int num, int v, int tl, int tr, int l, int r) {
    if (tl == l and tr == r)
        return t[v+num*(1<<13)];
    int tm = (tl + tr) / 2;
    if (r<=tm) return get(num,2*v,tl,tm,l,r);
    if (l>tm) return get(num,2*v+1,tm+1,tr,l,r);
    return get(num,2*v,tl,tm,l,tm)+get(num,2*v+1,tm+1,tr,tm+1,r);
}


ll base = 1000000000;

vector<ll> mul(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<a.size();i++)
    {
        for (int j=0;j<b.size();j++)
        {
            res[i+j] += a[i]*b[j];
        }
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sum(vector<ll> a, vector<ll> b)
{
    if (a.size()<b.size())
    {
        swap(a,b);
    }
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]+b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]>base)
        {
            res[i+1] += res[i]/base;
            res[i] %= base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}

vector<ll> sub(vector<ll> a, vector<ll> b)
{
    vector<ll> res(a.size()+b.size());
    for (int i=0;i<b.size();i++)
    {
        res[i] += a[i]-b[i];
    }
    for (int i=b.size();i<a.size();i++)
    {
        res[i] = a[i];
    }
    for (int i=0;i<res.size();i++)
    {
        if (res[i]<0)
        {
            res[i+1]--;
            res[i] += base;
        }
    }
    for (int i=res.size()-1;i>0;i--)
    {
        if (res[i]==0)
        {
            res.pop_back();
        }
        else
        {
            break;
        }
    }
    return res;
}*/



int main() {
    ios_base::sync_with_stdio(false);
    ll n, r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<ll> a(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    ll INF = 1000000000000000000LL;
    vector<ll> dp1(n+1,INF), dp2(n+1,INF);
    dp1[0] = d*(n-1);
    ll ans = INF;
    for (int i=0;i<n;i++)
    {
        dp1[i+1] = min(dp1[i+1],a[i]*r1+r3+dp1[i]);
        dp1[i+1] = min(dp1[i+1],r2+r1+2*d+dp1[i]);
        dp1[i+1] = min(dp1[i+1],r1*a[i]+2*r1+2*d+dp1[i]);
        dp2[i + 1] = min(dp2[i + 1], r1 * a[i] + 2 * r1 + d + dp1[i]);
        dp2[i + 1] = min(dp2[i + 1], r2 + r1 + d + dp1[i]);
        dp2[i + 1] = min(dp2[i + 1], a[i] * r1 + r3 + dp2[i] + d);
        dp2[i + 1] = min(dp2[i + 1], r2 + r1 + d + dp2[i]);
        dp2[i + 1] = min(dp2[i + 1], r1 * a[i] + 2 * r1 + d + dp2[i]);
        if (i==n-2)
        {
            ans = min(ans,dp1[i]+r1*a[i]+2*r1+r1*a[i+1]+2*r1+2*d);
            ans = min(ans,dp1[i]+r2+r1+r1*a[i+1]+2*r1+2*d);
            ans = min(ans,dp1[i]+r1*a[i]+2*r1+r2+r1+2*d);
            ans = min(ans,dp1[i]+r2+r1+r2+r1+2*d);
            ans = min(ans,dp1[i]+r2+r1+r1*a[i+1]+r3+d);
            ans = min(ans,dp2[i]+r2+r1+r1*a[i+1]+r3+d);
            ans = min(ans,dp1[i]+r1*a[i]+2*r1+r1*a[i+1]+r3+d);
            ans = min(ans,dp2[i]+r1*a[i]+2*r1+r1*a[i+1]+r3+d);
        }
        if (i<=n-2)
        {
            dp1[i+2] = min(dp1[i+2],dp1[i]+r1*a[i]+2*r1+r1*a[i+1]+2*r1+2*d);
            dp1[i+2] = min(dp1[i+2],dp1[i]+r2+r1+r1*a[i+1]+2*r1+2*d);
            dp1[i+2] = min(dp1[i+2],dp1[i]+r2+r1+r2+r1+2*d);
            dp1[i+2] = min(dp1[i+2],dp1[i]+r1*a[i]+2*r1+r2+r1+2*d);
        }
        if (i==n-1)
        {
            dp2[i + 1] = min(dp2[i + 1], a[i] * r1 + r3 + d + dp2[i]);
        }
    }
    ans = min(ans,dp1[n]);
    ans = min(ans,dp2[n]+d);
    cout << ans << endl;
}