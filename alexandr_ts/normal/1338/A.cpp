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

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int N = 1e6 + 10;

ll a[N];
ll b[N];

void solve() {
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];	
	}
	b[0] = a[0];
	for (int i = 1; i < n; ++i) {
		b[i] = max(b[i - 1], a[i]);	
	}
	for (int i = 0; i < n; ++i) {
		ll x = b[i] - a[i];	
		ll cnt = 0;
		while (x) {
			cnt++;
			x /= 2;	
		}
		ans = max(ans, cnt);
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