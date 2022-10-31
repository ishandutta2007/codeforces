#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<pair<int, int> > vp;
int AREA(int a, int b, int c) {
	int X1 = vp[b].first - vp[a].first;
	int Y1 = vp[b].second - vp[a].second;
	int X2 = vp[c].first - vp[a].first;
	int Y2 = vp[c].second - vp[a].second;

	return (X1 * Y2 - X2 * Y1);
}
int ask(int t, int a, int b, int c) {
	cout << t << " " << a + 1 << " " << b + 1 << " " << c + 1 << endl << flush;
	cin >> a;
	return a;

	if (t == 1) {
		return abs(AREA(a, b, c));
	}
	else {
		int t = AREA(a, b, c);
		return t / abs(t);
	}
}

struct X {
	int area;
	int b;
	int idx;
	bool operator<(const X &right) const {
		if (area < 0 && right.area > 0) {
			return true;
		}
		if (area > 0 && right.area < 0) {
			return false;
		}
		if (b == right.b) {
			return ((area < right.area) == (area > 0))== (b == 1);
		}
		return b > right.b;
	}
};
signed main() {
	int N;
	cin >> N;
	/*vp.emplace_back(0, 3);
	vp.emplace_back(0, -3);
	vp.emplace_back(2, -2);
	vp.emplace_back(-3, 0);
	vp.emplace_back(3, 0);
	vp.emplace_back(2, 2);
	vp.emplace_back(-2, 2);
	vp.emplace_back(-2, -2);*/

	/*vp.emplace_back(-3, 0);
	vp.emplace_back(0, -3);
	vp.emplace_back(2, -2);
	vp.emplace_back(3, 0);
	vp.emplace_back(2, 2);
	vp.emplace_back(0, 3);
	vp.emplace_back(-2, 2);*/
	vector<X> res(N - 2);
	for (int i = 2; i < N; i++) {
		res[i - 2].idx = i;
	}
	int mxi = -1;
	int mx = 0;
	int mni = -1;
	int mn = 0;

	for (int i = 2; i < N; i++) {
		res[i - 2].area = ask(1, 0, 1, i) * ask(2, 0, 1, i);
		if (mx < res[i - 2].area) {
			mx = res[i - 2].area;
			mxi = i;
		}
		if (mn > res[i - 2].area) {
			mn = res[i - 2].area;
			mni = i;
		}
	}
	for (int i = 2; i < N; i++) {
		if (res[i - 2].area > 0) {
			if (res[i - 2].idx != mxi) {
				cerr << res[i - 2].idx + 1 << " " << mxi + 1 << " " << 2 << endl;
				res[i - 2].b = ask(2, res[i - 2].idx, mxi, 1);
			}
		}
		else {
			if (res[i - 2].idx != mni) {
				cerr << res[i - 2].idx + 1 << " " << mni + 1 << " " << 1 << endl;
				res[i - 2].b = ask(2, res[i - 2].idx, mni, 0);
			}
		}
	}
	cerr << "Ok" << endl;
	sort(res.begin(), res.end());
	cout << 0 << " " << 1;
	int c = -1;
	for (int i = 0; i < N - 2; i++) {
		if (c == -1 && res[i].area > 0) {
			cout << " " << 2;
			c = 0;
		}
		cout << " " << res[i].idx + 1;
	}
	if (c == -1) {
		cout << " " << 2;
	}
	cout << endl;
	cout << flush;
}