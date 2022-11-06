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
#include <stack>
#include <memory>

using namespace std;

void sort(vector<int> &a, vector<int> &b) {
	vector<pair<int, int>> v(a.size());
	for (int i = 0; i < v.size(); ++i)
		v[i] = { a[i], b[i] };
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		a[i] = v[i].first;
		b[i] = v[i].second;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, T;
	cin >> n >> T;
	vector<int> a(n), t(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	sort(t, a);
	
	if (T < t[0] || T > t.back()) {
		cout << 0;
		return 0;
	}

	vector<double> cs(n), wcs(n);
	for (int i = 0; i < n; ++i) {
		cs[i] = a[i] + (i ? cs[i - 1] : 0);
		wcs[i] = (double)a[i] * t[i] + (i ? wcs[i - 1] : 0);
	}

	int i;
	double _cs, _wcs;
	
	const double epsylon = 1e-8;

	if (wcs[n - 1] / cs[n - 1] < T - epsylon) {
		i = 0;
		while (i != n - 1 && (wcs[n - 1] - wcs[i]) / (cs[n - 1] - cs[i]) < T - epsylon)
			++i;
		_wcs = wcs[n - 1] - wcs[i];
		_cs = cs[n - 1] - cs[i];
	}
	else if (wcs[n - 1] / cs[n - 1] > T + epsylon) {
		i = n - 1;
		while (i && wcs[i - 1] / cs[i - 1] > T + epsylon)
			--i;
		_wcs = wcs[i - 1];
		_cs = cs[i - 1];
	}
	else {
		cout << cs[n - 1];
		return 0;
	}
	cout << fixed << setprecision(8);
	cout << _cs + (T*_cs - _wcs) / (t[i] - T);
	return 0;
}