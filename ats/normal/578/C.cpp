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
double res;
vector<int> A;
int N;
bool isTooBig(double x) {
	double mn_sofar = 0;
	double mx_sofar = 0;
	double sum = 0;
	double mn = 0;
	double mx = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] - x;
		mn = min(mn, sum - mx_sofar);
		mx = max(mx, sum - mn_sofar);
		mx_sofar = max(mx_sofar, sum);
		mn_sofar = min(mn_sofar, sum);
	}
	res = min(abs(mn), abs(mx));
	if (abs(mn) > abs(mx))return true;
	return false;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	double  toobig = 1e12;
	double  toosmall = -1e12;

	for (int t = 0; t < 100; t++) {
		double mid = (toobig + toosmall) * 0.5;

		if (isTooBig(mid)) {
			toobig = mid;
		}
		else {
			toosmall = mid;
		}
	}

	isTooBig((toobig + toosmall) * 0.5);

	cout << fixed << setprecision(15) << res << endl;
}