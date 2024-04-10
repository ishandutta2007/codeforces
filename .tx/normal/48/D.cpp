#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct rec {
	int x, id;
};

bool mfunc(const rec & a, const rec & b) {
	return a.x < b.x;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, i;
	cin >> n;
	vector<rec> a(n);
	vector<int> ans(n);
	vector<int> c;
	for (i = 0; i < n; i++) {
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a.begin(), a.end(), mfunc);
	int m, l, r, x;
	for (i = 0; i < n; i++) {
		l = 0;
		r = c.size();
		x = a[i].x;
		while (l < r) {
			m = (l + r) >> 1;
			if (c[m] >= x) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		if (l >= c.size()) {
			if (x == 1) {
				c.push_back(x);
			}
			else {
				cout << -1;
				return 0;
			}
		}
		else {
			if (c[l] + 1 != x) {
				cout << -1;
				return 0;
			}
			c[l] = x;
		}
		ans[a[i].id] = l;
	}
	cout << c.size() << endl;
	for (i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
	return 0;
}//yverxh