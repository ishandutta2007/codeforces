//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;

map<ll,ll> num;
vector<ll> cur;
ll A = 0;

vector<pair<ll,pair<ll,ll>>> prv;

void rec2(ll p, ll mn)
{
    ll x = prv[p].X;
    for (ll w=x;w<mn;w+=x)
    {
        ll pos = num[w];
        ll F = 0;
        for (ll d=0;d<prv.size();d++)
        {
            if (cur[pos]%prv[d].X==0)
            {
                F = 1;
                break;
            }
        }
        if (F==1) continue;
        prv.push_back({cur[pos],{p,pos}});
        rec2(prv.size()-1,mn);
    }
}

void rec(ll a)
{
    prv.clear();
    prv.push_back({a,{-1,-1}});
    ll mn = 0;
    while (true)
    {
        ll D = mod;
        ll p = -1;
        for (ll i=0;i<prv.size();i++)
        {
            ll x = prv[i].X;
            ll W = mn/x*x+x;
            if (D>W)
            {
                p = i;
                D = W;
            }
        }
        mn = D;
        ll pos = num[mn];
        if (cur[pos]==-1)
        {
            A += mn;
            while (p!=-1)
            {
                cur[pos] = prv[p].X;
                pos = prv[p].Y.Y;
                p = prv[p].Y.X;
            }
            return;
        }
        ll F = 0;
        for (ll d=0;d<prv.size();d++)
        {
            if (cur[pos]%prv[d].X==0)
            {
                F = 1;
                break;
            }
        }
        if (F==1) continue;
        prv.push_back({cur[pos],{p,pos}});
        rec2(prv.size()-1,mn);
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll Q = 0;
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for (ll i=0;i<n;i++)
    {
        for (ll d=1;d<=n;d++)
        {
            ll x = a[i]*d;
            if (num.count(x)==0)
            {
                num[x] = Q++;
                cur.push_back(-1);
            }
        }
        rec(a[i]);
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}