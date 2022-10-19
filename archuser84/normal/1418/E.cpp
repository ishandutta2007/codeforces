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

const int mod = 998'244'353;
const int N = 200'010;
int d[N];
ll par[N];
int n, q;

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

int main()
{
    FAST;
    cin >> n >> q;
    Loop(i,0,n)
        cin >> d[i];
    sort(d, d+n);
    par[0]=0;
    Loop(i,0,n)
        par[i+1] = (par[i]+d[i])%mod;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int sml = lower_bound(d, d+n, b) - d;
        int big = n - sml;
        ll ans = 0;
        if(big >= a)
            ans += modDivide(par[sml]*(big+1-a)%mod, big+1, mod);
        if(big-1 >= a)
            ans += modDivide((par[n]-par[sml]+mod)%mod*(big-a)%mod, big, mod);
        ans %= mod;
        cout << ans << '\n';
    }
}