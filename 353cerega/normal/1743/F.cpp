//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;


ll t[1200000][2][2];

void set0(ll v)
{

    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            t[v][i][j] = 0;
        }
    }
    for (ll i=0;i<2;i++)
    {
        t[v][i][i]++;
        t[v][i][0]++;
        t[v][i][i]++;
    }
}

void set1(ll v)
{
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            t[v][i][j] = 0;
        }
    }
    for (ll i=0;i<2;i++)
    {
        t[v][i][1]++;
        t[v][i][i]++;
        t[v][i][i^1]++;
    }
}

void recalc(ll v)
{
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            t[v][i][j] = 0;
        }
    }
    for (ll i=0;i<2;i++)
    {
        for (ll j=0;j<2;j++)
        {
            for (ll k=0;k<2;k++)
            {
                t[v][i][k] = (t[v][i][k]+t[2*v][i][j]*t[2*v+1][j][k])%mod;
            }
        }
    }
}

void build(ll v, ll tl, ll tr)
{
    if (tl==tr)
    {
        set0(v);
        return;
    }
    ll tm = (tl+tr)/2;
    build(v*2,tl,tm);
    build(v*2+1,tm+1,tr);
    recalc(v);
}

void upd(ll v, ll tl, ll tr, ll p, ll b)
{
    if (tl==tr)
    {
        if (b==0) set0(v);
        else set1(v);
        return;
    }
    ll tm = (tl+tr)/2;
    if (tm>=p) upd(v*2,tl,tm,p,b);
    else upd(v*2+1,tm+1,tr,p,b);
    recalc(v);
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g;
    ll mx = 300010;
    g.resize(mx+1);
    vector<vector<ll>> A(mx+1), R(mx+1);
    for (ll i=0;i<n;i++)
    {
        ll l, r;
        cin >> l >> r;
        A[l].push_back(i);
        R[r+1].push_back(i);
    }
    build(1,1,n-1);
    vector<ll> a(n);
    ll W = 0;
    for (ll p=0;p<=mx;p++)
    {
        for (ll x: A[p])
        {
            if (x==0) a[x] = 1;
            else upd(1,1,n-1,x,1);
        }
        for (ll x: R[p])
        {
            if (x==0) a[x] = 0;
            else upd(1,1,n-1,x,0);
        }
        W = (W+t[1][a[0]][1])%mod;
    }
    cout << W << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}