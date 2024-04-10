//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;


using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;



void solve()
{
    ll n;
    cin >> n;
    if (n<=2)
    {
        for (ll j=1;j<=n;j++) cout << j << " ";
        cout << "\n";
        return;
    }
    cout << 1 << " ";
    for (ll x=3;x<=n;x++) cout << x << " ";
    cout << 2 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    cin >> T;
    while (T--) solve();
}