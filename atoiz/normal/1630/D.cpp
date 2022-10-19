/*input
3
6 2
0 6 -2 1 -4 5
1 2
7 1
1 -1 1 -1 1 1 -1
2
5 1
-1000000000 -1000000000 -1000000000 -1000000000 -1000000000
1

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		
		int b = 0;
		while (m--) { int x; cin >> x; b = __gcd(x, b); }

		int64_t ans = 0;
		vector<int> flip(n, 0), neg(b, 0), mn_abs(b, 2e9);
		int l = 0, s = 0;
		for (int r = 0; r < n; ++r) {
			ans += abs(a[r]);
			mn_abs[r % b] = min(mn_abs[r % b], abs(a[r]));

			for (; l + b <= r; ++l) s ^= flip[l];
			if (r <= n - b) flip[r] = ((a[r] < 0) ^ s);
			s ^= flip[r];
			// cout << "d " << r << ": " << s << endl;
			if (s) a[r] = -a[r];
			if (r > n - b && a[r] < 0) neg[r % b] = true;
		}

		array<int64_t, 2> bad = {0, 0};
		for (int i = 0; i < b; ++i) bad[neg[i]] += mn_abs[i];

		// for (int i = 0; i < b; ++i) cout << neg[i]; cout << endl;
		// for (int i = 0; i < n; ++i) cout << flip[i]; cout << endl;
		// cout << bad[0] << ' ' << bad[1] << endl;
		cout << ans - 2 * min(bad[0], bad[1]) << '\n';
	}

	return 0;
}