#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cassert>
#include <set>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using vi = vector<int>;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vi xs(n);
	for (auto& x : xs) cin >> x;
	int A;
	cin >> A;
	vi cs(n);
	for (auto& c : cs) cin >> c;
	ll ans = 0;
	multiset<int> cheap;
	for (int i = 0; i < n; i++) {
		cheap.insert(cs[i]);
		while (k < xs[i] && !cheap.empty()) {
			ans += *cheap.begin();
			cheap.erase(cheap.begin());
			k += A;
		}
		if (k < xs[i]) {
			return cout << -1, 0;
		}
	}
	cout << ans;
}