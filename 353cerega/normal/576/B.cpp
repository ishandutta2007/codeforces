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
    vector<ll> p(n);
    for (ll i=0;i<n;i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (ll i=0;i<n;i++)
    {
        if (i==p[i])
        {
            cout << "YES\n";
            for (ll j=0;j<n;j++)
            {
                if (i==j) continue;
                cout << i+1 << " " << j+1 << "\n";
            }
            return;
        }
    }
    for (ll i=0;i<n;i++)
    {
        if (p[p[i]]!=i) continue;
        vector<pair<ll,ll>> e;
        e.push_back({i,p[i]});
        vector<ll> was(n);
        was[i] = was[p[i]] = 1;
        ll F = 0;
        for (ll u=0;u<n;u++)
        {
            if (was[u]==1) continue;
            ll w = 0;
            ll v = u;
            while (was[v]==0)
            {
                if (w==0) e.push_back({v,i});
                else e.push_back({v,p[i]});
                w ^= 1;
                was[v] = 1;
                v = p[v];
            }
            if (w==1)
            {
                F = 1;
                break;
            }
        }
        if (F==1) break;
        cout << "YES\n";
        for (auto x: e)
        {
            cout << x.X+1 << " " << x.Y+1 << "\n";
        }
        return;
    }
    cout << "NO\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}