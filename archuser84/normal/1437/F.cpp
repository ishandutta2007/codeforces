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

const int mod = 998244353;
const int N = 5'010;

ll dp[N][N]={};
int a[N];
int n;

ll modDiv(ll x, ll y, ll mod = ::mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDiv(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

ll fact[N];
ll inv[N];

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];
    sort(a, a+n);

    fact[0] = 1;
    Loop(i,1,N)
        fact[i] = fact[i-1]*i%mod;
    Loop(i,0,N)
        inv[i] = modDiv(1, fact[i]);

    dp[0][0] = 1;
    Loop(n, 1, ::n+1)
    {
        int k = upper_bound(a,a+n,a[n-1]/2) - a;
        ll sum = 0;
        Loop(r, 0, k+2)
            dp[n][r] = (dp[n-1][r] + inv[k-r+1]*sum)%mod,
            sum = (sum + dp[k][r]*fact[k-r])%mod;
        Loop(r, k+2, n)
            dp[n][r] = dp[n-1][r];
    }

    cout << dp[n][n] << '\n';
}