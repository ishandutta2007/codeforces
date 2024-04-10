#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex>
#include <ctime>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a[i];
		--a[i];
	}

	int k = 0;
	for (; 1 << k < n; ++k);

	vector<vector<int>> p(n), q(n);
	for (int i = 0; i < n; ++i) {
		p[i].resize(k);
		q[i].resize(k);
	}

	for (int i = 0; i < n; ++i) {
		p[i][0] = a[i];
		q[i][0] = i;
	}

	vector<int> d(n);
	d[0] = 0;
	d[1] = 0;
	for (int i = 2; i < n; ++i)
		d[i] = d[i / 2] + 1;

	for (int j = 1; j < k; ++j)
		for (int i = 0; i < n; ++i) {
			p[i][j] = max(p[i][j - 1], (i + (1 << (j - 1)) >= n ? 0 : p[i + (1 << (j - 1))][j - 1]));
			q[i][j] = (p[i][j] == p[i][j - 1] ? q[i][j - 1] : q[i + (1 << (j - 1))][j - 1]);
		}

	vector<long long> res(n);
	res[n - 1] = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] == n - 1) {
			res[i] = n - i - 1;
			continue;
		}
		int l = d[a[i] - (i + 1)];
		int x = (p[i + 1][l] > p[a[i] - (1 << l) + 1][l] ?
				 q[i + 1][l] : q[a[i] - (1 << l) + 1][l]);
		res[i] = res[x] + (long long)(x - i) + (long long)(n - a[i] - 1);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += res[i];
	cout << ans << endl;
    return 0;
}