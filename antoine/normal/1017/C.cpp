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

int floorSqrt(int n) {
	int r = sqrt(n);
	while ((r + 1)*(r + 1) <= n) ++r;
	while (r*r > n) --r;
	return r;
}

void solve() {
	int n;
	cin >> n;
	const int r = floorSqrt(n);
	vector<int> cnts(r, n / r);
	for (int i = 0; i < n%r; ++i)
		cnts[i]++;

	assert(accumulate(cnts.begin(), cnts.end(), 0) == n);

	int curr = n;
	for(auto &&cnt : cnts) {
		curr -= cnt;
		for (int j = 1; j <= cnt; ++j)
			cout << curr + j << ' ';
	}
	assert(!curr);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}