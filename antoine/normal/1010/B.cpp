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

int m;

int query(int x) {
	assert(x >= 1 && x <= m);
	cout << x << endl;
	fflush(stdout);

	cin >> x;
	static int numReq = 0;
	assert(++numReq <= 60);
	assert(x != -2);
	if (x == 0) {
		exit(0);
		return 0;
	}
	if (x == 1 || x == -1)
		return x;
	exit(0);
	assert(x == 1 || x == -1);
	return x;
}

int main() {
	int n;
	cin >> m >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		a.at(i) = query(1);
	int lo = 1;
	int hi = m;
	for (int i = 0;; ++i) {
		assert(lo <= hi);
		int mid = (lo + hi) / 2;
		if (query(mid) * a.at(i % n) == 1)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
	return 0;
}