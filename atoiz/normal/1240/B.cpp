/*input
3
7
3 1 6 6 3 1 1
8
1 1 4 4 4 7 8 8
7
4 2 5 2 6 2 7

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
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

int solve()
{
	int n; cin >> n;
	vector<int> min_app(n, n), max_app(n, -1), v1, v2;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; --x;
		min_app[x] = min(min_app[x], i);
		max_app[x] = max(max_app[x], i);
	}
	for (int i = 0; i < n; ++i) {
		if (max_app[i] >= 0) {
			v1.push_back(min_app[i]);
			v2.push_back(max_app[i]);
		}
	}

	int ans = 0;
	for (int l = 0, r = 1; l < SZ(v1); l = r) {
		for (r = l + 1; r < SZ(v1) && v2[r - 1] < v1[r]; ++r);
		ans = max(ans, r - l);
	}
	return SZ(v1) - ans;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while (q--) cout << solve() << endl;

	return 0;
}