#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int MAXN = 100000;

int main() {
	// freopen("input.txt", "r", stdin);

	int n;
	long long r;
	cin >> n >> r;
	vector<long long> l(n), t(n);
	for (int i = 0; i < n; ++i)
		cin >> l[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];

	long long cur = 0;
	long long ans = 0;
	long long tm = 0;

	vector<long long> res;

	for (int i = 0; i < n; ++i) {
		if (l[i] > t[i]) {
			cout << "-1" << endl;
			return 0;
		}

		if (cur >= l[i]) {
			cur -= l[i];
			tm += l[i];
			continue;
		}

		l[i] -= cur;
		t[i] -= cur;
		tm += cur;
		cur = 0;
		if (2 * l[i] <= t[i]) {
			tm += 2 * l[i];
			continue;
		}

		long long x = 2 * (t[i] - l[i]);
		tm += x;
		l[i] -= x / 2;
		t[i] -= x;
		int y = (t[i] - 1) / r + 1;
		for (long long j = 0; j < y && sz(res) < MAXN; ++j)
			res.push_back(tm + j * r);
		cur = r * y - l[i];
		tm += l[i];
		ans += y;
	}

	cout << ans << endl;

	if (ans <= MAXN) {
		for (int i = 0; i < sz(res); ++i)
			cout << res[i] << " ";
		cout << endl;
	}


}