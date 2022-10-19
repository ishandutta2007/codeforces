#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <cassert>
#include <array>

using namespace std;

int solve(array<set<pair<int, int>>, 2> &pnts)
{
	array<array<set<pair<int, int>>::iterator, 2>, 2> it;
	array<set<pair<int, int>>, 2> split = {};
	it[0][0] = pnts[0].begin(), it[0][1] = prev(pnts[0].end());
	it[1][0] = pnts[1].begin(), it[1][1] = prev(pnts[1].end());

	while (true) {
		if (it[0][1] == pnts[0].begin()) return 1;

		if (it[0][0]->first + 1 < next(it[0][0])->first) {
			split[0] = set<pair<int, int>>(pnts[0].begin(), next(it[0][0]));
			pnts[0].erase(pnts[0].begin(), next(it[0][0]));
			for (auto &p : split[0]) {
				pnts[1].erase(make_pair(p.second, p.first));
				split[1].emplace(p.second, p.first);
			}
		} else if (prev(it[0][1])->first + 1 < it[0][1]->first) {
			split[0] = set<pair<int, int>>(it[0][1], pnts[0].end());
			pnts[0].erase(it[0][1], pnts[0].end());
			for (auto &p : split[0]) {
				pnts[1].erase(make_pair(p.second, p.first));
				split[1].emplace(p.second, p.first);
			}
		} else if (it[1][0]->first + 1 < next(it[1][0])->first) {
			split[1] = set<pair<int, int>>(pnts[1].begin(), next(it[1][0]));
			pnts[1].erase(pnts[1].begin(), next(it[1][0]));
			for (auto &p : split[1]) {
				pnts[0].erase(make_pair(p.second, p.first));
				split[0].emplace(p.second, p.first);
			}
		} else if (prev(it[1][1])->first + 1 < it[1][1]->first) {
			split[1] = set<pair<int, int>>(it[1][1], pnts[1].end());
			pnts[1].erase(it[1][1], pnts[1].end());
			for (auto &p : split[1]) {
				pnts[0].erase(make_pair(p.second, p.first));
				split[0].emplace(p.second, p.first);
			}
		} else {
			++it[0][0], --it[0][1], ++it[1][0], --it[1][1];
			continue;
		}

		break;
	}

	return solve(split) + solve(pnts);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	array<set<pair<int, int>>, 2> pnts = {};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		pnts[0].emplace(x, y);
		pnts[1].emplace(y, x);
	}

	cout << solve(pnts) << endl;
}