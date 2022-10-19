///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 1e9+7;
const int N = 3010;
bool a[N][N];
ll dp[N][N];
int n, m;

ll cnt(int x1, int y1, int x2, int y2)
{
	memset(dp, 0, sizeof(dp));
	dp[x1][y1] = !a[x1][y1];
	Loop (i,x1,x2+1) Loop (j,y1,y2+1) {
		if (a[i][j])
			continue;
		if (j > y1)
			dp[i][j] += dp[i][j-1];
		if (i > x1)
			dp[i][j] += dp[i-1][j];
		dp[i][j] %= mod;
	}
	return dp[x2][y2];
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop (i,0,n) Loop (j,0,m) {
		char c;
		cin >> c;
		a[i][j] = c == '#';
	}
	ll ans = cnt(0,1,n-2,m-1)*cnt(1,0,n-1,m-2) - cnt(0,1,n-1,m-2)*cnt(1,0,n-2,m-1);
	ans = (ans%mod+mod)%mod;
	cout << ans << '\n';
}