#include <algorithm>
#include <iostream>
#include <map>
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

int a[N];

void solve() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
	}
	sort(a, a + n, greater<int>());
	int ans = 0;
	ll sum = 0;
	for (ll i = 0; i < n; ++i) {
		sum += a[i];
		if (sum >= (ll)x * (i + 1)) {
			ans = i + 1;	
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