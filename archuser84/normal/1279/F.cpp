///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 1e6+10;
int a[N];
int n, k, len;

pll dp[N];

pll solve(ll lambda)
{
	dp[0] = {};
	Loop (i,0,n) {
		dp[i+1] = dp[i];
		dp[i+1].first += a[i];
		int j = max(0ll, i-len);
		pll tmp = dp[j];
		tmp.first += lambda;
		tmp.second++;
		dp[i+1] = min(dp[i+1], tmp);
	}
	return dp[n];
}

ll bin_search()
{
	ll l=0, r=N;
	while (l < r) {
		ll m = (l+r)/2;
		ll x = solve(m).second;
		if (x <= k)
			r = m;
		else
			l = m+1;
	}
	return solve(l).first - l*k;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k >> len; --len;
	Loop (i,0,n) {
		char c;
		cin >> c;
		a[i] = c <= 'Z';
	}
	ll ans = bin_search();
	Loop (i,0,n) a[i] = !a[i];
	ans = min(ans, bin_search());
	cout << ans << '\n';
}