/*input
4
8 7
16 15
4 2
4 3

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
		int n, k; cin >> n >> k;
		if (k == n - 1) {
			if (n == 4) {
				cout << "-1\n";
				continue;
			} else {
				FOR(i, 0, n / 2 - 4) cout << i << ' ' << n - 1 - i << '\n';
				cout << n / 2 << ' ' << n / 2 + 2 << '\n';
				cout << n / 2 - 3 << ' ' << n / 2 + 1 << '\n';
				cout << n / 2 - 1 << ' ' << n / 2 - 2 << '\n';
				continue;
			}
		}
		if (k == 0) {
			FOR(i, 0, n / 2 - 1) cout << i << ' ' << n - 1 - i << '\n';
			continue;
		} 
		FOR(i, 1, n / 2 - 1) {
			if (i == k) {
				cout << 0 << ' ' << n - 1 - i << '\n';
				cout << n - 1 << ' ' << i << '\n';
			} else if (n - 1 - i == k) {
				cout << 0 << ' ' << i << '\n';
				cout << n - 1 << ' ' << n - 1 - i << '\n';
			} else {
				cout << i << ' ' << n - 1 - i << '\n';
			}
		}
	}

	return 0;
}