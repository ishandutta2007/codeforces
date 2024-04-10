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
double min_d2(double x1, double y1, double x2, double y2) {
	double a = x2 - x1;
	double b = y2 - y1;
	double a2 = a * a;
	double b2 = b * b;
	double r2 = a2 + b2;
	double tt = -(a*(x1) + b * (y1));
	if (tt < 0) {
		return (x1)*(x1) + (y1)*(y1);
	}
	if (tt > r2) {
		return (x2)*(x2) + (y2)*(y2);
	}
	double f1 = a * (y1) - b * (x1);
	return (f1*f1) / r2;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, X, Y;
	cin >> N >> X >> Y;
	vector<int> A(N);
	vector<int> B(N);
	int res = 0;
	double mn = 1e15;
	double mx = -1;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		double a = (A[i] - X) * (A[i] - X) + (B[i] - Y) * (B[i] - Y);
		mx = max(mx, a);
	}
	for (int i = 0; i < N; i++) {
		int X1 = A[i] - X;
		int Y1 = B[i] - Y;
		int X2 = A[(i + 1) % N] - X;
		int Y2 = B[(i + 1) % N] - Y;
		double a = min_d2(X1, Y1, X2, Y2);
		mn = min(mn, a);
	}


	cout << fixed << setprecision(15) << (mx - mn) * 3.14159265358979323846 << endl;
}