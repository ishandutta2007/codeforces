#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <type_traits>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
#include <ostream>
#include <iterator>
#include <new>
#include <cstdlib>
#include <tuple>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;


const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;


void solve() {
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll> ans;
	ll cur = 1;
	while (cur < n) {
		ll cnt = (n - cur) * 2;
		if (cnt < l) {
			cur++;	
			l -= cnt;
			r -= cnt;
		} else break;
	}
	for (ll i = cur; i < n; ++i) {
		for (ll j = i + 1; j <= n; ++j) {
			ans.push_back(i);
			ans.push_back(j);
		}	
		if (ans.size() > (size_t)r) break;
	}
	ans.push_back(1);
	l--, r--;
	vector<int> rez{ans.begin() + l, ans.begin() + r + 1};
	for (auto el: rez) cout << el << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}