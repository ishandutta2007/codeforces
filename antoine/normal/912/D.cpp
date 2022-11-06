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

using namespace std;

void preComp(long long * v, long long * cs, long long n, long long r) {
	v[0] = v[n - 1] = 1;
	for (int i = 1, j = n - 2; i < (n + 1) / 2; ++i, --j)
		v[i] = v[j] = min(r, (i + r <= n) ? (v[i - 1] + 1) : v[i - 1]);

	cs[0] = v[0];
	for (int i = 1; i < n; ++i)
		cs[i] = cs[i - 1] + v[i];
}

long long getCS(long long * v, int i, int j) {
	if (i)
		return v[j] - v[i - 1];
	return v[j];
}

struct Response {
	long long countGE;
	long long maxValueLess;
	long long sum;
};

long long n, m, r, k;

long long row[(int)1e5];
long long col[(int)1e5];
long long rowCS[(int)1e5];
long long colCS[(int)1e5];

Response feasable(const long long minV) {
	Response res;
	res.maxValueLess = -1;
	res.countGE = 0;
	res.sum = 0;

	for (int i = 0; i < n; ++i) {
		int lo = 0;
		int hi = (m + 1) / 2 - 1;

		if (row[i] * col[hi] < minV) {
			res.maxValueLess = max(res.maxValueLess, row[i] * col[hi]);
			continue;
		}
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (row[i] * col[mid] >= minV)
				hi = mid;
			else
				lo = mid + 1;
		}
		if (lo)
			res.maxValueLess = max(res.maxValueLess, row[i] * col[lo - 1]);
		hi = m - 1 - lo;
		res.countGE += hi - lo + 1;
		//cout << "i, lo, hi: " << i << ' ' << lo << ' ' << hi << '\n';
		res.sum += row[i] * getCS(colCS, lo, hi);
	}
	//cout << '\n';
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r >> k;

	preComp(row, rowCS, n, r);
	preComp(col, colCS, m, r);

	long long lo = 0;
	long long hi = n*m;


	long long ans = 0;

	while (lo < hi) {
		long long mid = (lo + hi) / 2;
		auto res = feasable(mid);
		if (res.countGE <= k) {
			hi = mid;
			ans = res.sum + (k - res.countGE) * res.maxValueLess;
		}
		else
			lo = mid + 1;
	}

	cout << setprecision(12) << (double)ans / ((n - r + 1)*(m - r + 1));

	return 0;
}