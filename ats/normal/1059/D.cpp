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
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> X(N);
	vector<int> Y(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
	}
	bool ok = true;
	for (int i = 0; i < N; i++) {
		if (Y[i] < 0) {
			ok = false;
			break;
		}
	}
	if (!ok) {
		ok = true;
		for (int i = 0; i < N; i++) {
			Y[i] = -Y[i];
			if (Y[i] < 0) {
				ok = false;
				break;
			}
		}
	}
	if (ok) {
		double u = 1e14 + 1;
		double d = 0;
		for (int i = 0; i < N; i++) {
			d = max(d, Y[i] * 0.5);
		}
		d += 1e-9;
		double m;
		for (int t = 0; t < 100; t++) {
			m = (u + d) / 2;
			double mx = 1e8;
			double mn = -1e8;

			for (int i = 0; i < N; i++) {
				double ra = sqrt(2 * m * Y[i] - Y[i] * Y[i]);
				//cerr << m << " " << ra << endl;
				mx = min(mx, X[i] + ra);
				mn = max(mn, X[i] - ra);
			}
			if (mx > mn) {
				u = m;
			}
			else {
				d = m;
			}
		}
		cout << fixed << setprecision(15) << m << endl;
	}
	else {
		cout << -1 << endl;
	}
}