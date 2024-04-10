#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

void solve()
{
	int k;
	cin >> k;
	ll sum = 0;
	set<pll, greater<pll>> s;
	Loop (i,0,k) {
		ll x;
		cin >> x;
		s.insert({x, i});
		sum += x;
	}
	vector<ll> fib;
	while (sum > 0) {
		int len = fib.size();
		if (len < 2)
			fib.push_back(1);
		else
			fib.push_back(fib[len-1] + fib[len-2]);
		sum -= fib.back();
	}
	if (sum < 0) {
		cout << "NO\n";
		return;
	}
	int lst = -1;
	while (fib.size()) {
		auto it = s.begin();
		ll mx = it->first;
		if (it->second == lst)
			++it;
		if (it == s.end() || it->first != mx) {
			cout << "NO\n";
			return;
		}
		auto [x, i] = *it;
		if (x < fib.back()) {
			cout << "NO\n";
			return;
		}
		s.erase({x, i});
		s.insert({x-fib.back(), i});
		fib.pop_back();
		lst = i;
	}
	cout << "YES\n";
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}