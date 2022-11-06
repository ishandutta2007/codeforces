#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int p[(int) 2e3 + 9];
bool taken[(int) 2e3 + 9];

void play(int x) {
	cout << x << endl;
	taken[x] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= 2 * n; ++i)
		cin >> p[i];

	vector<pair<int, int>> v(m);
	for (auto &&x : v)
		cin >> x.first >> x.second;

	int t;
	cin >> t;
	t &= 1;

	int forced = -1;
	for (int round = 0; round < 2 * n; ++round, t ^= 1) {
		if (t) {
			if (forced != -1) {
				play(forced);
				forced = -1;
			} else {
				bool done = false;
				for (auto &&x : v) {
					assert(taken[x.first] == taken[x.second]);
					if (!taken[x.first]) {
						play(p[x.first] > p[x.second] ? x.first : x.second);
						done = true;
						break;
					}
				}
				if (!done) {
					int best = -1;
					for (int i = 1; i <= 2 * n; ++i)
						if (!taken[i] && (best == -1 || p[best] < p[i]))
							best = i;
					assert(best != -1);
					play(best);
				}
			}
		} else {
			int x;
			cin >> x;
			taken[x] = true;
			for (auto &&y : v)
				if (y.first == x || y.second == x) {
					if (!taken[y.first])
						forced = y.first;
					if (!taken[y.second])
						forced = y.second;
				}
		}
	}
	return 0;
}