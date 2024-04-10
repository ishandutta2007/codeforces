#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

void solve()
{
    ll p, q;
    cin >> p >> q;
    ll ans = 1;
    for(ll d = 2; d*d <= q; ++d)
    {
        if(q % d)
            continue;
        ll x = p;
        while(x % q == 0)
            x /= d;
        ans = max(ans, x);
        while(q % d == 0)
            q /= d;
    }
    if(q > 1)
    {
        ll d = q;
        ll x = p;
        while(x % q == 0)
            x /= d;
        ans = max(ans, x);
        while(q % d == 0)
            q /= d;
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}