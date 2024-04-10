/*input
5
1 1 1 10 1
1 1 1 1 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>> vec(N);
	for (int i = 0; i < N; ++i) cin >> vec[i].first;
	for (int i = 0; i < N; ++i) cin >> vec[i].second;

	int64_t totalCost = 0;
	sort(vec.begin(), vec.end());
	int curVal = 0, id = 0;
	priority_queue<int> curPubs;
	int64_t curCost = 0;

	while (!curPubs.empty() || id < (int) vec.size()) {
		if (curPubs.empty()) {
			curVal = vec[id].first;
		}

		while (id < (int) vec.size() && vec[id].first == curVal) {
			curCost += vec[id].second;
			curPubs.push(vec[id].second);
			++id;
		}

		assert(!curPubs.empty());
		curCost -= curPubs.top();
		curPubs.pop();
		totalCost += curCost;
		++curVal;
	}

	cout << totalCost << endl;
	return 0;
}