///
///   You fell for it, fool!
///   Thunder Cross Split Attack!
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
typedef long long ll;
using namespace std;

ll mpow(ll x, ll y){return y? x*mpow(x,y-1): 1;}

void solve()
{
	ll a[12];
	ll n, rem;
	cin >> n >> rem; ++rem;
	ll ans = 0;
	Loop(i,0,n) cin >> a[i];
	Loop(i,0,n-1)
	{
		if(rem >= mpow(10, a[i+1]-a[i])-1){
			rem -= mpow(10, a[i+1]-a[i])-1;
			ans += (mpow(10, a[i+1]-a[i])-1)*mpow(10,a[i]);
		} else {
			ans += rem*mpow(10,a[i]);
			rem = 0;
		}
	}
	ans += rem*mpow(10,a[n-1]);
	cout << ans << '\n';
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