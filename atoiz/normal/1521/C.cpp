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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;

		int k = [](int n) {
			for (int i = 1, x; i + 1 <= n; i += 2) {
				cout << "? 1 " << i << ' ' << i + 1 << ' ' << n - 1 << endl;
				cin >> x;
				if (x == n) return i + 1;
				if (x == n - 1) {
					cout << "? 1 " << i + 1 << ' ' << i << ' ' << n - 1 << endl;
					cin >> x;
					if (x == n) return i;
				}
			}
			return n;
		} (n);

		vector<int> a(n + 1);
		FOR(i, 1, n) {
			if (i == k) {
				a[i] = n;
				continue;
			}

			cout << "? 2 " << i << ' ' << k << " 1" << endl;
			cin >> a[i];
		}
		cout << '!';
		FOR(i, 1, n) cout << ' ' << a[i];
		cout << endl;
	}

	return 0;
}