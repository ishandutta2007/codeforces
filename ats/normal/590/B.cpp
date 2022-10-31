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
	int X1, Y1, X2, Y2;
	cin >> X1 >> Y1 >> X2 >> Y2;
	int V, T;
	cin >> V >> T;
	int vx, vy;
	int wx, wy;
	cin >> vx >> vy;
	cin >> wx >> wy;

	double ok = 1e18;
	double ng = 0;
	for (int i = 0; i < 100; i++) {
		double m = (ok + ng) * 0.5;
		double X = X2 - m * vx;
		double Y = Y2 - m * vy;
		double dist = hypot(X - X1, Y - Y1);
		if (dist / V < m) {
			ok = m;
		}
		else {
			ng = m;
		}
	}
	double res;
	if (ok < T) {
		res = ok;
	}
	else {
		double ok = 1e18;
		double ng = T;
		for (int i = 0; i < 100; i++) {
			double m = (ok + ng) * 0.5;
			double X = X2 - T * vx - (m - T)* wx;
			double Y = Y2 - T * vy - (m - T)* wy;
			double dist = hypot(X - X1, Y - Y1);
			if (dist / V < m) {
				ok = m;
			}
			else {
				ng = m;
			}
		}
		res = ok;
	}
	cout << fixed << setprecision(15) << res << endl;
}