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
		vector<ll> a(n), dp(n+1), px(n+1);
		Loop (i,0,n)
			cin >> a[i];
		Loop (i,0,n)
			px[i+1] = px[i] ^ a[i];
		map<int, int> lst;
		Loop (i,0,n) {
			lst[px[i]] = i;
			if (lst.count(px[i+1])) {
				int l = lst[px[i+1]];
				dp[i+1] = min(dp[i]+1, i-l + dp[l]);
			} else {
				dp[i+1] = dp[i]+1;
			}
		}
		cout << dp[n] << '\n';
	}
}