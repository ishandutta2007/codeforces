#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;

	while (t--) {

		auto calc = [](ll n) {
			ll x = floorl(sqrtl((long double) n));
			while (x * x > n) x--;
			while ((x + 1) * (x + 1) <= n) x++;
			ll ans = x * 3;
			if (x * x + 2 * x > n) ans--;
			if (x * x + x > n) ans--;
			return ans;
		};
		
		ll l, r;
		cin >> l >> r;
		cout << calc(r) - calc(l - 1) << '\n';
	}
	return 0;
}