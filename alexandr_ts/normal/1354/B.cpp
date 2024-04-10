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
const ll MOD = 998244353;
const int N = 1e6 + 10;

int l[3][N];

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < 3; ++i) {
		fill(l[i], l[i] + n + 1, -INF);	
	}
	ll ans = INF;
	for (int i = 0; i < n; ++i) {
		if (i) {
			for (int j = 0; j < 3; ++j) {
				l[j][i] = l[j][i - 1];
			}	
		}
		l[s[i] - '1'][i] = i;
		ll l1 = i - l[0][i] + 1;
		ll l2 = i - l[1][i] + 1;
		ll l3 = i - l[2][i] + 1;
		ans = min(ans, max({l1, l2, l3}));
	}

	if (ans >= INF) {
		cout << "0\n";
	} else {
		cout << ans << "\n";
	}

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