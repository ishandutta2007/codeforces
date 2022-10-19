///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
typedef long long ll;
using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll ans = 1;
	ll cnt = 0;
	while(ans < n && ans <= k)
	{
		++cnt;
		ans *= 2;
	}
	if(ans >= n)
		cout << cnt << '\n';
	else
		cout << cnt+(n-ans+k-1)/k << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}