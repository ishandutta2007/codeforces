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

ll a[N];
ll b[N], c[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		c[i] = min(a[i], b[i > 0 ? i - 1 : n - 1]);
	}
	ll sum = accumulate(a, a + n, 0ll);
	ll sumc = accumulate(c, c + n, 0ll);
	ll minc = *min_element(c, c + n);
	cout << sum - sumc + minc << "\n";

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