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
		vector<int> a(n);
		int l=0, r=0;
		Loop (i,0,n) {
			cin >> a[i];
			r += a[i];
		}
		reverse(a.begin(), a.end());
		int ans = r;
		Loop (i,0,n) {
			l += a[i] == 0;
			r -= a[i] == 1;
			ans = min(ans, r + max(l-r, 0));
		}
		cout << ans << '\n';
	}
}