#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	multiset<int> maxX1, maxY1, minX2, minY2;

	int n;
	cin >> n;
	vector<int> x1(n), y1(n), x2(n), y2(n);

	for (int i = 0; i < n; ++i) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		maxX1.insert(x1[i]);
		maxY1.insert(y1[i]);
		minX2.insert(x2[i]);
		minY2.insert(y2[i]);
	}

	for (int i = 0; i < n; ++i) {
		maxX1.erase(maxX1.find(x1[i]));
		maxY1.erase(maxY1.find(y1[i]));
		minX2.erase(minX2.find(x2[i]));
		minY2.erase(minY2.find(y2[i]));

		if (*maxX1.rbegin() <= *minX2.begin() && *maxY1.rbegin() <= *minY2.begin()) {
			cout << *maxX1.rbegin() << ' ' << *maxY1.rbegin() << '\n';

			return 0;
		}
		maxX1.insert(x1[i]);
		maxY1.insert(y1[i]);
		minX2.insert(x2[i]);
		minY2.insert(y2[i]);
	}

	assert(false);
	return 0;
}