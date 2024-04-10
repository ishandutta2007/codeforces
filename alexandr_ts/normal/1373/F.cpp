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
const int N = 2e6 + 10;
const int MAX = 1e5 + 1;

int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
		a[i + n] = a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];	
		b[i + n] = b[i];
	}
	b[0] = b[n];
	if (accumulate(a, a + n, 0ll) > accumulate(b, b + n, 0ll)) {
		cout << "NO\n";
		return;	
	}
	n *= 2;
	ll mx = 0;
	ll suma = 0, sumb = 0;
	for (int i = 0; i <= n; ++i) {
		if (sumb + b[i] - suma - mx < 0) {
			cout << "NO\n";
			return;	
		}	
		sumb += b[i];
		suma += a[i];
		mx = max(mx, sumb - suma);
	}
	cout << "YES\n";
	
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