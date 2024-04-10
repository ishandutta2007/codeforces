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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *a = new int[n];
		Loop (i,0,n) cin >> a[i];
		--n;
		Loop (i,0,n)
			a[i] = a[i] == a[i+1];
		int mn = 0, mx = n-1;
		while (mn < n && !a[mn]) ++mn;
		while (mx && !a[mx]) --mx;
		if (mn >= mx) cout << "0\n";
		else cout << max(1, mx-mn-1) << '\n';
		delete[](a);
	}
}