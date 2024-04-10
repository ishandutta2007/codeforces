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
#include <iomanip>
#include <cmath>
#include <numeric>

#define debug(x) cout << #x << " is " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1e9 + 10;
const ll MOD = 998244353;
const ld PI = acos(-1);
const int N = 1e6 + 10;


void solve() {
	int n;
	cin >> n;
	ld a = PI / n;
	ld y = sqrt(1 / (2 - 2 * cos(a)));
	ld ans = INF;

	for (int i = 1; i * 2 <= n; ++i) {
		if (a * (i + 1) * 2 >= PI) {
			ans = min(ans, 2 * y * sin(PI / 4 + i * a / 2));	
		}
	}

	cout << fixed << setprecision(12) << ans << "\n";
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