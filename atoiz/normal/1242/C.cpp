/*input
4
3 1 7 4
2 3 2
2 8 5
1 10

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
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>

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

const int MAXK = 16, PUSH = 4, MAXV = 5002 * MAXK;
int K;
vector<int> vals[MAXK];
map<long long, int> mapping;
int to[MAXV];
int cycles[1 << MAXK];
int C[MAXK], P[MAXK];

void getTrace(int mask)
{
	if (cycles[mask] < 0) {
		int mask1 = -cycles[mask];
		getTrace(mask1);
		getTrace(mask ^ mask1);
		return;
	}

	int start = cycles[mask];
	for (int cur = start;; cur = to[cur]) {
		assert(cur);

		int id = cur & ((1 << PUSH) - 1);
		int nxtId = to[cur] & ((1 << PUSH) - 1);
		int valId = cur >> PUSH;

		P[nxtId] = id;
		C[id] = vals[id][valId];
		if (to[cur] == start) {
			break;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> K;
	FOR(i, 1, K) {
		int n;
		cin >> n;
		vals[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> vals[i][j];
			mapping[vals[i][j]] = (j << PUSH) ^ i;
		}
	}

	long long total = 0;
	FOR(i, 1, K) total += accumulate(ALL(vals[i]), 0ll);
	if (total % K) return cout << "No" << endl, 0;
	total /= K;
	FOR(i, 1, K) {
		ll diff = accumulate(ALL(vals[i]), -total);
		FOR(j, 0, SZ(vals[i]) - 1) {
			if (mapping.find(vals[i][j] - diff) != mapping.end()) {
				to[(j << PUSH) ^ i] = mapping[vals[i][j] - diff];
				// cout << i << ' ' << j << ": " << (to[(j << PUSH) ^ i] & ((1 << PUSH) - 1)) << ' ' << (to[(j << PUSH) ^ i] >> PUSH) << endl;
			} 
		}
	}

	FOR(i, 1, K) {
		FOR(j, 0, SZ(vals[i]) - 1) {
			int curMask = 0, start = (j << PUSH) ^ i;
			bool exist = 1;
			for (int cur = start; exist; cur = to[cur]) {
				if (cur == 0) {
					exist = 0;
					break;
				}

				int id = cur & ((1 << PUSH) - 1);

				if ((curMask >> (id - 1)) & 1) {
					exist = 0;
					break;
				}

				curMask |= (1 << (id - 1));

				if (to[cur] == start) {
					break;
				}
			}

			if (exist) {
				cycles[curMask] = start;
			}
		}
	}

	FOR(mask, 1, (1 << K) - 1) {
		for (int mask1 = mask & (mask - 1); mask1 && !cycles[mask]; mask1 = mask & (mask1 - 1)) {
			if (cycles[mask1] && cycles[mask ^ mask1]) {
				cycles[mask] = -mask1;
			}
		}
	}

	if (!cycles[(1 << K) - 1]) return cout << "No" << endl, 0;
	getTrace((1 << K) - 1);
	cout << "Yes\n";
	FOR(i, 1, K) {
		cout << C[i] << ' ' << P[i] << '\n';
	}

	return 0;
}