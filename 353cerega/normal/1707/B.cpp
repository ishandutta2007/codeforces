#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

const ll mod = 1000000007;
//const ll mod = 998244353;


void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<pair<ll,ll>> x;
    for (ll i=0;i<n;i++)
    {
        if (x.size()!=0 and x.back().X==a[i]) x.back().Y++;
        else x.push_back({a[i],1});
    }
    while (x.size()>1 and (x.size()>2 or x[0].X!=0))
    {
        vector<ll> a2;
        ll C0 = 0;
        for (ll i=0;i<x.size();i++)
        {
            C0 += x[i].Y-1;
            if (i>0) a2.push_back(x[i].X-x[i-1].X);
        }
        sort(a2.begin(),a2.end());
        x.clear();
        if (C0>0) x.push_back({0,C0});
        for (ll w: a2)
        {
            if (x.size()!=0 and x.back().X==w) x.back().Y++;
            else x.push_back({w,1});
        }
    }
    ll pos = x.size()-1;
    if (pos==1 or x[pos].Y==1) cout << x[pos].X << "\n";
    else cout << 0 << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}