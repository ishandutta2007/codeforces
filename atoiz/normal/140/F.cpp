/*input
4 2
0 0
0 1
1 0
1 1

*/

// spoiled

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (n == k) return cout << -1 << endl, 0;

	vector<pair<int, int>> pnts(n), res;
	for (auto &p : pnts) cin >> p.first >> p.second;
	sort(pnts.begin(), pnts.end());

	for (int i1 = 0; i1 <= k; ++i1) {
		for (int i2 = n - 1 - k; i2 < n; ++i2) {
			int sum_x = pnts[i1].first + pnts[i2].first;
			int sum_y = pnts[i1].second + pnts[i2].second;

			int add = 0;
			for (int i = 0, j = n - 1; i < n; ++i) {
				for (; j >= 0 && make_pair(pnts[i].first + pnts[j].first, pnts[i].second + pnts[j].second) > make_pair(sum_x, sum_y); --j);
				if (j < 0 || pnts[i].first + pnts[j].first != sum_x || pnts[i].second + pnts[j].second != sum_y) {
					++add;
				}
			}

			if (add <= k) {
				res.emplace_back(sum_x, sum_y);
			}
		}
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	cout << res.size() << '\n';
	cout << fixed << setprecision(1);
	for (auto &p : res) {
		cout << p.first * 0.5 << ' ' << p.second * 0.5 << '\n';
	}
}