/*input
13
1 2 3 2 1 3 3 4 5 5 5 4 7

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

	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> last(n + 1);

	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) last[a[i]] = i;

	int ans = n;
	for (int i = 1; i <= n;) {
		if (i == last[a[i]]) { --ans; ++i; continue; }

		ans -= 2;
		int r = last[a[i]], nr = r;
		while (true) {
			for (; i <= r; ++i) {
				nr = max(nr, last[a[i]]);
			}
			if (nr == r) break;
			--ans, r = nr;
		}
	}
	cout << ans << endl;

	return 0;
}