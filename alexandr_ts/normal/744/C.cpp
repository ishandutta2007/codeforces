#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 16;
const int INF = (int)2e9;

struct Card {
	char col;
	int r;
	int b;
} a[N];

map<pair<int, int>, int> dp[(1 << N)];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].col >> a[i].r >> a[i].b;
	}

	dp[0][{0, 0}] = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int A = 0, B = 0;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				if (a[i].col == 'R') {
					++A;
				}
				else {
					++B;
				}
			}
		}

		for (auto [pr, cnt]: dp[mask]) {
			int r = pr.first, b = pr.second;
			for (int nxt = 0; nxt < n; ++nxt) {
				if (mask & (1 << nxt)) {
					continue;
				}
				int cost_r = max(0, a[nxt].r - A);
				int cost_b = max(0, a[nxt].b - B);
				int add_steps = max(cost_r - r, cost_b - b);
//				assert(add_steps >= 0);
				int r1 = r + add_steps - cost_r;
				int b1 = b + add_steps - cost_b;
				assert(r1 == 0 || b1 == 0);
				auto it = dp[mask | (1 << nxt)].find({ r1, b1 });
				if (it != dp[mask | (1 << nxt)].end()) {
					it->second = min(
						it->second,
						cnt + add_steps
					);
				}
				else {
					dp[mask | (1 << nxt)][{ r1, b1 }] = cnt + add_steps;
				}
			}
		}
	}

	int mask = (1 << n) - 1;
	int ans = INF;
	for (auto& el : dp[mask]) {
		ans = min(ans, el.second);
	}
	cout << ans + n << endl;
}

int main() {
	solve();
}