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
#include <unordered_map>
#include <cstring>
#include <array>
#include <variant>
#include <any>
#include <experimental/filesystem>
#include <fstream>
#include <numeric>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const int N = 1e6 + 10;

vector<ll> a[3];

ll solve2(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
	ll ans = 5 * INF * INF;
	for (auto x: a) {
		vector<ll> cands;
		auto it_b = lower_bound(b.begin(), b.end(), x);
		if (it_b != b.end()) {
			cands.push_back(*it_b);	
		}
		if (it_b != b.begin()) {
			cands.push_back(*(prev(it_b)));	
		}
		vector<ll> cands_z;
		for (auto y: cands) {
			auto it_c = lower_bound(c.begin(), c.end(), (x + y) / 2);	
			if (it_c != c.end()) {
				cands_z.push_back(*it_c);	
			}
			if (it_c != c.begin()) {
				cands_z.push_back(*prev(it_c));	
			}
		}
		for (auto y: cands) {
			for (auto z: cands_z) {
				ans = min(ans, (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z));
			}
		}
	}
	return ans;
}

void solve() {
	vector<int> perm = {0, 1, 2};
	vector<int> n(3);
	for (int i = 0; i < 3; ++i) {
		cin >> n[i];	
	}
	for (int i = 0; i < 3; ++i) {
		a[i].resize(n[i]);
		for (int j = 0; j < n[i]; ++j) {
			cin >> a[i][j];
		}	
		sort(a[i].begin(), a[i].end());
	}
	ll ans = 5 * INF * INF;
	do {
		ans = min(ans, solve2(a[perm[0]], a[perm[1]], a[perm[2]]));	
	} while (next_permutation(perm.begin(), perm.end()));
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