/*input
3
6 1
6 3 6 7 3 3
3 6
2 0
3 4
7 4
1 2 2 3 1 5 1
1 5
3 5
1 3
2 5

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
		int n, m; cin >> n >> m;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());

		vector<vector<int>> vec(n + 1);
		vector<int> app;
		for (int l = 0, r = l; l < n; l = r) {
			while (r < n && a[l] == a[r]) ++r;
			vec[r - l].push_back(a[l]);
			app.push_back(r - l);
		}

		sort(app.begin(), app.end());
		app.erase(unique(app.begin(), app.end()), app.end());

		vector<int64_t> bad(m);
		auto enc = [](int x, int y) { return (int64_t) x << 30 | y; };
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			bad[i] = enc(x, y);
		}
		sort(bad.begin(), bad.end());
		auto is_bad = [&](int x, int y) {
			if (x == y) return true;
			if (x > y) swap(x, y);
			auto it = lower_bound(bad.begin(), bad.end(), enc(x, y));
			return it != bad.end() && (*it) == enc(x, y);
		};

		for (int i = 0; i <= n; ++i) sort(vec[i].rbegin(), vec[i].rend());
		int64_t ans = 0;
		for (int a0 : app) for (int x : vec[a0]) {
			for (int a1 : app) for (int y : vec[a1]) {
				if (!is_bad(x, y)) {
					ans = max(ans, (int64_t) (a0 + a1) * (x + y));
					break;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}