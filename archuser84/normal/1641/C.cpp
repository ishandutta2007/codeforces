///
///   Oh? You're approaching me?
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
	int n, q;
	cin >> n >> q;
	map<int, int> mp;
	Loop (i,0,n) mp[i] = n+1;

	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int l, r, x;
			cin >> l >> r >> x; --l;
			if (x == 0) {
				auto it = mp.lower_bound(l);
				int mn = n+1;
				while (it != mp.end() && it->first < r) {
					mn = min(mn, it->second);
					mp.erase(it++);
				}
				if (it != mp.end())
					it->second = min(mn, it->second);
			} else {
				auto it = mp.lower_bound(l);
				if (it != mp.end())
					it->second = min(r, it->second);
			}
		} else {
			int i;
			cin >> i; --i;
			auto it = mp.find(i);
			if (it != mp.end()) {
				auto tmp = mp.upper_bound(i);
				int j = tmp == mp.end()? n: tmp->first;
				cout << (j < it->second? "N/A": "YES") << '\n';
			} else {
				cout << "NO" << '\n';
			}
		}
	}
}