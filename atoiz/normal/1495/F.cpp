/*input
3 2
2 1 3
10 -5 4
3 -2 3
1
2

*/

// umm, maybe? ...
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cassert>

using namespace std;

const int MAXN = 200007, LOG = 18;
int N, Q, P[MAXN], nxt[MAXN], prv[MAXN], jumpDest[LOG][MAXN], backDest[LOG][MAXN];
int64_t jumpCost[LOG][MAXN], backCost[LOG][MAXN], A[MAXN], B[MAXN], curCost[MAXN], curTotal;
set<int> forced;

int64_t getJumpCost(int s, int t) {
	int64_t cost = 0;
	for (int j = LOG - 1; j >= 0; --j) {
		if (jumpDest[j][s] <= t) {
			cost += jumpCost[j][s];
			s = jumpDest[j][s];
		}
	}
	assert(s == t);
	return cost;
}

int64_t getCost(int s, int t) {
	int64_t cost = 0;
	for (int j = LOG - 1; j >= 0; --j) {
		if (jumpDest[j][s] <= t) {
			cost += jumpCost[j][s];
			s = jumpDest[j][s];
		}
		if (backDest[j][t] >= s) {
			cost += backCost[j][t];
			t = backDest[j][t];
		}
	}
	assert(s == t);
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> P[i];
	for (int i = 1; i <= N; ++i) cin >> A[i];
	for (int i = 1; i <= N; ++i) cin >> B[i];

	P[0] = N + 1, P[N + 1] = N + 1;
	for (int j = 0; j < LOG; ++j) {
		jumpDest[j][N + 1] = N + 1;
		jumpCost[j][N + 1] = 0;

		backDest[j][0] = 0;
		backCost[j][0] = 0;
	}

	for (int i = N; i >= 1; --i) {
		for (nxt[i] = i + 1; P[nxt[i]] < P[i]; nxt[i] = nxt[nxt[i]]);

		if (P[i] < P[i + 1]) B[i] = min(B[i], A[i]);
		else B[i] = min(B[i], A[i] + getJumpCost(i + 1, nxt[i]));

		jumpDest[0][i] = nxt[i], jumpCost[0][i] = B[i];
		for (int j = 1; j < LOG; ++j) {
			int x = jumpDest[j - 1][i];
			jumpDest[j][i] = jumpDest[j - 1][x];
			jumpCost[j][i] = jumpCost[j - 1][i] + jumpCost[j - 1][x];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (prv[i] = i - 1; P[prv[i]] < P[i]; prv[i] = prv[prv[i]]);

		int64_t c;
		if (P[i] < P[i - 1]) c = A[i - 1];
		else c = A[prv[i]] + getJumpCost(prv[i] + 1, i);

		backDest[0][i] = prv[i], backCost[0][i] = c;
		for (int j = 1; j < LOG; ++j) {
			int x = backDest[j - 1][i];
			backDest[j][i] = backDest[j - 1][x];
			backCost[j][i] = backCost[j - 1][i] + backCost[j - 1][x];
		}
	}

	forced.insert(1);
	forced.insert(N + 1);
	curTotal = curCost[1] = getCost(1, N + 1);
	while (Q--) {
		int x;
		cin >> x;

		if (x != 1) {
			set<int>::iterator i;
			bool add;
			tie(i, add) = forced.insert(x);
			if (!add) {
				curTotal -= curCost[*i] + curCost[*prev(i)];
				curTotal += (curCost[*prev(i)] = getCost(*prev(i), *next(i)));
				forced.erase(i);
			} else {
				curTotal -= curCost[*prev(i)];
				curTotal += (curCost[*prev(i)] = getCost(*prev(i), *i));
				curTotal += (curCost[*i] = getCost(*i, *next(i)));
			}
		}
		cout << curTotal << '\n';
	}
}