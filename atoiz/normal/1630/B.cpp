/*input
3
2 1
1 2
4 2
1 2 2 2
11 3
5 5 5 1 5 5 1 5 5 5 1

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

const int MAXN = 200007;
int a[MAXN], b[MAXN], s[MAXN], en[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		FOR(i, 1, n) cin >> a[i];

		FOR(i, 1, n) b[i] = a[i];
		sort(b + 1, b + 1 + n);

		int mn = n + 1, d = (k + n + 1) / 2 - 1;
		FOR(i, 1, n - d) mn = min(mn, b[i + d] - b[i]);
		int l = 0;
		FOR(i, 1, n - d) if (mn == b[i + d] - b[i]) { l = i; break; }
		assert(l);

		int lo = b[l], hi = b[l + d];
		cout << b[l] << ' ' << b[l + d] << '\n';

		s[0] = 0;
		FOR(i, 1, n) s[i] = s[i - 1] + ((a[i] >= lo && a[i] <= hi) ? 1 : -1);
		// cout << s[n] << ' ' << k << ' ' << d << endl;
		assert(s[n] >= k);

		en[0] = 0;
		FOR(i, 1, k - 1) en[i] = find(en[i - 1] + ALL(s), i) - begin(s); en[k] = n;
		FOR(i, 1, k) cout << en[i - 1] + 1 << ' ' << en[i] << '\n';
	}

	return 0;
}