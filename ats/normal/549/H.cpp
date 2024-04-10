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
vector<double> v(4);
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	double a, b;
	cin >> a >> b;
	double c, d;
	cin >> c >> d;
	double uu = 1e18 + 1;
	double dd = 0;

	double xx[2][2];
	double l1, r1;
	double l2, r2;
	for (int i = 0; i < 100; i++) {
		double m = (uu + dd)*0.5;
		xx[0][0] = a - m;
		xx[0][1] = a + m;
		xx[1][0] = d - m;
		xx[1][1] = d + m;


		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				v[j + k * 2] = xx[0][j] * xx[1][k];

			}
		}
		sort(v.begin(), v.end());
		l1 = v[0]; r1 = v.back();
		xx[0][0] = b - m;
		xx[0][1] = b + m;
		xx[1][0] = c - m;
		xx[1][1] = c + m;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				v[j + k * 2] = xx[0][j] * xx[1][k];
			}
		}
		sort(v.begin(), v.end());
		l2 = v[0]; r2 = v.back();

		if (r1 < l2 || l1 > r2) {
			dd = m;
		}
		else {
			uu = m;
		}
	}
	cout << fixed << setprecision(15) << uu << endl;
}