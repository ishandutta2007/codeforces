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

const int INF = 2e9;

const int MAXN = 11000;

int main() {
	// freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	vector<pair<int, int>> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> r[i].first;
		r[i].second = i;
	}

	sort(all(r));

	for (int i = r[0].first; i > 0; --i) {
		vector<pair<int, int>> v = r;;
		for (int j = 0; j < n; ++j)
			v[j].first -= i;

		int sum = 0;
		for (int j = 0; j < n; ++j)
			sum += v[j].first;

		vector<vector<int>> q;
		if (sum & 1) {
			if (n < 3 || v[n - 3].first == 0)
				continue;
			--v[n - 1].first;
			--v[n - 2].first;
			--v[n - 3].first;
			q.push_back({v[n - 3].second, v[n - 2].second, v[n - 1].second});
			sum -= 3;
		}

		int mx = 0;
		for (int i = 0; i < n; ++i)
			mx = max(mx, v[i].first);

		if (2 * mx > sum)
			continue;

		for (; ; ) {
			int x = 0;
			int y = -1;
			for (int j = 1; j < n; ++j) {
				if (v[j].first > v[x].first) {
					y = x;
					x = j;
				}
				else {
					if (y == -1 || v[j].first > v[y].first) 
						y = j;
				}
			}

			if (v[x].first == 0 && v[y].first == 0)
				break;
			--v[x].first;
			--v[y].first;

			q.push_back({v[x].second, v[y].second});
		}

		cout << i << endl;
		cout << sz(q) << endl;
		for (int j = 0; j < sz(q); ++j) {
			vector<int> a(n);
			for (int k = 0; k < sz(q[j]); ++k)
				a[q[j][k]] = 1;
			for (int k = 0; k < n; ++k)
				cout << a[k];
			cout << endl;
		}
		return 0;
	}


	vector<vector<int>> q;
	cout << 0 << endl;

	for (; r[0].first > 0;) {
		vector<int> a(n);
		a[r[0].second] = 1;
		a[r[1].second] = 1;

		--r[0].first;
		--r[1].first;
		q.push_back({r[0].second, r[1].second});
	}

	for (int i = 1; i < n; ++i) {
		for (; r[i].first > 0; ) {
			vector<int> a(n);
			a[r[i].second] = 1;
			a[r[0].second] = 1;
			--r[i].first;
			q.push_back({r[0].second, r[i].second});
		}
	}


	cout << sz(q) << endl;
	for (int j = 0; j < sz(q); ++j) {
		vector<int> a(n);
		for (int k = 0; k < sz(q[j]); ++k)
			a[q[j][k]] = 1;
		for (int k = 0; k < n; ++k)
			cout << a[k];
		cout << endl;
	}
}