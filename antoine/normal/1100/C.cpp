#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	double r;
	cin >> n >> r;

	const double alfa = M_PI / n;

	double lo = 0;
	double hi = 1e10;
	for (int rep = 0; rep < 300; ++rep) {
		const double mid = (lo + hi) / 2.0;
		const double c = (r + mid) * sin(alfa);
		if (mid < c)
			lo = mid;
		else
			hi = mid;
	}
	cout << fixed << setprecision(10) << lo << endl;
	return 0;
}