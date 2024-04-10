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
		ll n, m, k;
		cin >> n >> m >> k;
		vector<ll> a(k);
		Loop (i,0,k)
			cin >> a[i];
		ll x = 0, y = 0;
		bool b1=0, b2=0;
		Loop (i,0,k) {
			if (a[i] >= 2*n)
				x += a[i]/n;
			if (a[i] >= 3*n)
				b1 = 1;
			if (a[i] >= 2*m)
				y += a[i]/m;
			if (a[i] >= 3*m)
				b2 = 1;
		}
		bool ans = 0;
		ans |= x >= m && (x%2 == m%2 || b1);
		ans |= y >= n && (y%2 == n%2 || b2);
		cout << (ans? "Yes": "No") << '\n';
	}
}