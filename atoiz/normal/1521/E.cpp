/*input

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

	int t;
	cin >> t;
	while (t--) {
		int m, k;
		cin >> m >> k;
		vector<int> a(k);
		FORA(x, a) cin >> x;
		int mx = *max_element(ALL(a)), n = 1;
		for (; m > n * n - (n / 2) * (n / 2) || mx > n * ((n + 1) / 2); ++n);
		vector<pair<int, int>> vec;
		for (int i = 1; i < n; i += 2) for (int j = 0; j < n; j += 2) vec.emplace_back(i, j);
		for (int i = 0; i < n; i += 2) for (int j = 0; j < n; j += 2) vec.emplace_back(i, j);
		for (int i = 0; i < n; i += 2) for (int j = 1; j < n; j += 2) vec.emplace_back(i, j);
		vector<vector<int>> b(n, vector<int>(n, 0));
		vector<int> c(k);
		iota(ALL(c), 0);
		sort(ALL(c), [&](int i, int j) { return a[i] > a[j]; });
		FORA(i, c) {
			while (a[i]--) {
				b[vec.back().first][vec.back().second] = i + 1;
				vec.pop_back();
			}
		}
		cout << n << '\n';
		FORA(v, b) {
			FORA(x, v) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}