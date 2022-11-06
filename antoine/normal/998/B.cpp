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
	cin.tie(0);
	cout.tie(0);

	int n, B;
	cin >> n >> B;

	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int diff = 0;
	vector<int> cuts;
	for (int i = 0; i + 1 < n; ++i) {
		diff += a[i] & 1 ? 1 : -1;
		if (!diff)
			cuts.push_back(abs(a[i] - a[i + 1]));
	}

	sort(cuts.begin(), cuts.end());
	partial_sum(cuts.begin(), cuts.end(), cuts.begin());
	cout << upper_bound(cuts.begin(), cuts.end(), B) - cuts.begin();

	return 0;
}