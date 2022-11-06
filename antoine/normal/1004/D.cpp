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

int t;
int maxNum = 0;
int maxComplete;
int occ[(int)1e6 + 2] = { 0 };
int occCS[(int)1e6 + 2] = { 0 };

bool complete(int diff) {
	if (!diff) return true;
	return occ[diff] == diff * 4;
}

void check(int n, int m, int r, int c) {
	static int localOcc[(int)1e6 + 2];
	memset(localOcc, 0, sizeof localOcc);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			++localOcc[abs(i - r) + abs(j - c)];
	for (int i = 0; i < t; ++i)
		if (localOcc[i] != occ[i])
			return;
	cout << n << ' ' << m << '\n';
	cout << r + 1 << ' ' << c + 1 << '\n';
	exit(0);
}

void f(int n, int m) { // r + c = maxNu,
	for (int r = 0, c = maxNum - r; c >= 0; ++r, --c)
		if (r < n && c < m && min(min(r, c), min(n - 1 - r, m - 1 - c)) == maxComplete)
			check(n, m, r, c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x;
		cin >> x;
		++occ[x];
		maxNum = max(maxNum, x);
	}
	partial_sum(occ, occ + t, occCS);
	int lo = 0;
	int hi = t;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (complete(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	maxComplete = lo;
	
	for (int n = 1; n <= t; ++n)
		if (t%n == 0)
			f(n, t / n);

	cout << -1;
	return 0;
}