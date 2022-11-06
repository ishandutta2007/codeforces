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

void done(int ans) {
	cout << "! " << (ans == -1 ? -1 : ans + 1) << endl;
	exit(0);
}

int n;

int qquery(int i) {
	assert(i >= 0 && i < n);
	cout << "? " << i + 1 << endl;
	cin >> i;
	return i;
}

bool test(int i) {
	assert(i >= 0 && i < n / 2);
	int diff = qquery(i + n / 2) - qquery(i);
	if (diff == 0) done(i);
	return diff > 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	assert(n % 2 == 0);
	if (n & 2) done(-1);

	int lo = 0;
	int hi = n / 2 - 1;
	const bool first = test(lo);
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (test(mid) == first)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	assert(lo == hi);
	test(lo);
	assert(false);
	return 0;
}