//#pragma GCC optimize("Ofast")
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
    vector<pair<pair<ll,ll>,ll>> a;
    for (ll i=0;i<n;i++)
    {
        ll x, y;
        cin >> x >> y;
        x /= 1000;
        if (x==1000) x--;
        if (x%2==1) y = 1000000-y;
        a.push_back({{x,y},i});
    }
    sort(a.begin(),a.end());
    for (ll i=0;i<n;i++)
    {
        cout << a[i].Y+1 << " ";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}