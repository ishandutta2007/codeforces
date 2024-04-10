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

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n;
	cin >> n;
	ll *a = new ll[n];
	Loop (i,0,n)
		cin >> a[i];
	ll ans = 1e18;
	Loop (i,0,n) {
		ll cnt = 0;
		ll lst = 0;
		Loop (j,i+1,n) {
			ll x = (lst+a[j])/a[j];
			cnt += x;
			lst = x*a[j];
		}
		lst = 0;
		LoopR (j,0,i) {
			ll x = (lst+a[j])/a[j];
			cnt += x;
			lst = x*a[j];
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}