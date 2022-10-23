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
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    ll p = 0;
    ll A = 0;
    for (ll j=1;j<=n;j++)
    {
        if (j==n or a[j]==a[j-1])
        {
            ll L = (j-p-1)/2;
            A = max(A,L);
            if (a[p]==a[j-1])
            {
                for (ll i=p+1;i<j-1;i++) a[i] = a[p];
            } else
            {
                for (ll i=1;i<=L;i++) a[i+p] = a[p], a[j-1-i] = a[j-1];
            }
            p = j;
        }
    }
    cout << A << "\n";
    for (ll x: a) cout << x << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}