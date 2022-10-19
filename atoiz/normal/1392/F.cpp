#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

const int64_t INF = 2e18;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int64_t> a(n);
	for (auto &x : a) cin >> x;
	
	vector<pair<int64_t, int>> st = {{a[n - 1] - (n - 1), 1}};
	st.reserve(n);

	for (int i = n - 2; i >= 0; --i) {
		int64_t x = a[i] - i;

		if (x > st.back().first) {
			st.emplace_back(x, 1);
			continue;
		}

		while (true) {
			assert(!st.empty());
			int64_t curSlope = st.back().first;
			assert(x <= curSlope);
			int curCnt = st.back().second;
			st.pop_back();

			int64_t nxtSlope = (st.empty() ? x - 1 : st.back().first);
			if (x + (curSlope - nxtSlope) * curCnt <= nxtSlope) {
				x += (curSlope - nxtSlope) * curCnt;

				assert(!st.empty());
				st.back().second += curCnt;
				if (x == nxtSlope) {
					++st.back().second;
					break;
				}
			} else {
				int64_t delta = (curSlope - x) / (curCnt + 1);
				x += delta * curCnt, curSlope -= delta;

				int cntAdd = (int) (curSlope - x), cnt = curCnt + 1 - cntAdd;
				x += cntAdd;
				int incAdd = 0, incCnt = 0;

				if (!st.empty() && st.back().first == x) cnt += st.back().second, st.pop_back();
				if (!st.empty() && st.back().first == x - 1) cntAdd += st.back().second, st.pop_back();

				if (cntAdd) st.emplace_back(x - 1, cntAdd);
				if (cnt) st.emplace_back(x, cnt);
				break;
			}
		}
	}

	for (int i = 0; !st.empty(); st.pop_back()) {
		int64_t slope = st.back().first;
		for (int cnt = st.back().second; cnt > 0; --cnt, ++i) cout << slope + i << ' ';
	}
}