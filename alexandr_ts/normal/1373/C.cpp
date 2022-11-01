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

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

void solve() {
	string s;
	cin >> s;
	int bal = 0;
	map<int, int> m;
	int i = 0;
	for (auto ch: s) {
		if (ch == '+') bal++;	
		else bal--;

		if (!m.count(bal)) {
			m[bal] = i;
		}
		i++;
	}

	ll ans = (int)s.size();
	for (auto [key, value]: m) {
		if (key < 0) {
			ans += (ll)value + 1;
		}
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