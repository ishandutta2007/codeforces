/*input
3
1
3
6
4
3 6 6 6
2 7 4 1
4
6 7 2 4
2 5 3 5

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
	#define int int64_t
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int s = 0, ans = 0;
		// if (n == 1) { cout << 0 << '\n'; cin >> s >> ans; continue; }
		bitset<30000> dp; dp[0] = 1;
		vector<int> a(n * 2);
		for (int i = 0; i < 2 * n; ++i) {
			int x; cin >> x; a[i] = x;
			ans += x * x;
			s += x;

			if (i < n) continue;
			dp = (dp << a[i]) | (dp << a[i - n]);
		}
		int p = s / 2;
		while (!dp[p]) --p;
		// cout << "p " << p << endl;

		ans *= n - 2;
		ans += p * p + (s - p) * (s - p);
		cout << ans << '\n';
	}

	return 0;
}