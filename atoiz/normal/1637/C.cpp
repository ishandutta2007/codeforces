/*input
5
3
1 13 1
5
1 2 2 3 6
3
1 3 1
3
1 2 1
4
3 1 1 2

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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;

	int c = 0;
	for (int i = 1; i < n - 1; ++i) if (a[i] & 1) ++c; 
	if (*max_element(a.begin() + 1, a.end() - 1) == 1) return cout << -1 << '\n', void();
	if (n == 3 && c == 1) return cout << -1 << '\n', void();

	int64_t tot = accumulate(a.begin() + 1, a.end() - 1, 0ll);
	return cout << (tot + c) / 2 << '\n', void();
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) solve();

	return 0;
}