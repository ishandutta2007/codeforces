#include <iostream>
#include <algorithm>
#include <map>
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

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int M = 1e3 + 10;
const int N = 1e6 + 10;

ll a[N];

void solve() {
	int n;
	cin >> n;
	map<int, ll> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
		a[i] -= i;
		m[a[i]] += (a[i] + i);
	}
	ll ans = 0;
	for (auto [k, v]: m) {
		ans = max(ans, v);	
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}