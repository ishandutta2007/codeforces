#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cassert>
#include <utility>
#include <functional>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>
 
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;


void solve() {
	ll k, m;
	cin >> k >> m;
	vector<ll> d(31, 0);
	d[0] = 1;
	for (int i = 1; (1 << i) <= k; ++i) {
		ll cnt = (1 << i);
		if ((1 << (i + 1)) > k) {
			cnt = k - (1 << i) + 1;
		}
		ll sum = 1;
		for (int j = 0; j < i; ++j) {
			sum = (sum + d[j]) % m;
		}
		d[i] = sum * (cnt % m) % m;
	}
	ll ans = 0;
	for (auto el: d) {
		ans += el;
		ans %= m;	
	}
	cout << ans << "\n";
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