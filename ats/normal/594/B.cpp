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
	int r;
	int v;
	cin >> r >> v;
	double res;
	int s, f;
	for (int i = 0; i < N; i++) {
		cin >> s >> f;
		double ok = 1e10;
		double ng = 0;
		for (int k = 0; k < 100; k++) {
			double m = (ok + ng) / 2;
			double X = f - s - v * m;

			double t = abs(2 * r * sin((m * v / r) / 2.0));
			if (X < t) {
				ok = m;
			}
			else {
				ng = m;
			}
		}
		cout << fixed << setprecision(15) << ok << endl;
	}
}