/*input
5
7 12
1 2 3 4 9 10 11
R R L L R R R
2 10
1 6
R R
2 10
1 3
L L
1 10
5
R
7 8
6 1 7 2 3 5 4
R L R L L L L

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

struct robot_t { int x, d, i; };

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ans(n, -1);
	vector<robot_t> a(n);
	FOR(i, 0, n - 1) cin >> a[i].x;
	FOR(i, 0, n - 1) {
		string s;
		cin >> s;
		a[i].d = (s == "R");
	}
	FOR(i, 0, n - 1) a[i].i = i;

	vector<vector<robot_t>> b(2);
	FOR(i, 0, n - 1) b[a[i].x & 1].push_back(a[i]);
	FORA(c, b) {
		sort(ALL(c), [](robot_t x, robot_t y) { return x.x < y.x; });
		vector<robot_t> stk;
		FORA(r, c) {
			if (r.d) { // R
				stk.push_back(r);
			} else {
				if (stk.empty()) {
					r.x = -r.x;
					r.d = !r.d;
					stk.push_back(r);
				} else {
					auto s = stk.back();
					stk.pop_back();
					int x = (r.x - s.x) / 2;
					ans[r.i] = ans[s.i] = x;
				}
			}
		}

		while (SZ(stk) >= 2) {
			auto r = stk.back();
			stk.pop_back();
			auto s = stk.back();
			stk.pop_back();
			r.x = 2 * m - r.x;
			ans[r.i] = ans[s.i] = (r.x - s.x) / 2;
		}
	}
	FORA(x, ans) printf("%d ", x);
	puts("");
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) solve();

	return 0;
}