/*input
3
6
3 6 5
5 2 4
5 4 6
6 3 1
6
2 5 6
2 5 1
4 1 2
1 3 5
3
1 2 3

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

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<set<int>> appIds(n + 1);

		vector<array<int, 3>> pieces(n - 2);
		FOR(id, 0, n - 3) {
			FORA(i, pieces[id]) {
				cin >> i;
				appIds[i].insert(id);
			}
		}

		stack<int> singles;
		FOR(i, 1, n) {
			if (SZ(appIds[i]) == 1) {
				singles.push(i);
			}
		}

		vector<int> vecP, vecQ;
		vecP.reserve(n);
		vecQ.reserve(n - 2);

		stack<int> finalIds, singledOut;
		while (!singles.empty()) {
			int i = singles.top();
			singles.pop();

			if (appIds[i].empty()) {
				continue;
			}

			singledOut.push(i);

			int id = *appIds[i].begin();
			finalIds.push(id);
			vecQ.push_back(id);

			FORA(j, pieces[id]) {
				appIds[j].erase(appIds[j].find(id));
				if (SZ(appIds[j]) == 1) {
					singles.push(j);
				}
			}
		}

		assert(SZ(finalIds) == n - 2);
		assert(SZ(singledOut) == n - 2);

		vector<int> prv(n + 1), nxt(n + 1);
		auto &arr = pieces[finalIds.top()];
		prv[arr[0]] = arr[2], prv[arr[1]] = arr[0], prv[arr[2]] = arr[1];
		nxt[arr[0]] = arr[1], nxt[arr[1]] = arr[2], nxt[arr[2]] = arr[0];
		// cout << "piece " << arr[0] << " -> " << arr[1] << " -> " << arr[2] << endl;

		finalIds.pop(); singledOut.pop();
		while (!finalIds.empty()) {
			arr = pieces[finalIds.top()];
			int z = singledOut.top();

			finalIds.pop(); singledOut.pop();

			int x = arr[0], y = arr[1];
			if (x == z) x = arr[2];
			else if (y == z) y = arr[2];
			if (prv[x] == y) swap(x, y);

			// cout << "piece " << x << " -> " << z << " -> " << y << endl;
			prv[nxt[z] = y] = nxt[prv[z] = x] = z;
		}

		for (int cur = 1; SZ(vecP) != n; cur = nxt[cur]) {
			vecP.push_back(cur);
		}

		FORA(i, vecP) cout << i << ' '; cout << '\n';
		FORA(i, vecQ) cout << i + 1 << ' '; cout << '\n';
	}

	return 0;
}