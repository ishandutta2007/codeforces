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

int n;

ll qry(int w)
{
	int cnt = 0;
	assert(cnt != n+30);
	++cnt;
	printf("? %d\n", w);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x == 0? n+1: x;
}

ll calc(ll w, ll h) {
	if (h == n+1)
		return 1e9;
	return w*h;
}

int main()
{
	cin >> n;
	ll l = 1, r = 4100000;
	while (l < r) {
		ll w = (l+r)/2;
		ll h = qry(w);
		if (h == 1)
			r = w;
		else
			l = w+1;
	}
	ll w = l;
	ll ans = 1e9;
	Loop(i,1,n+1)
		ans = min(ans, calc(w/i, qry(w/i)));
	cout << "! " << ans << '\n';
}