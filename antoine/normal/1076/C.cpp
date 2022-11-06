#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		int d;
		cin >> d;

		double lo = 0;
		double hi = d * .5;
		for (int rep = 300; rep; --rep) {
			const double mid = (lo + hi) * .5;
			if (mid * (d - mid) > d)
				hi = mid;
			else
				lo = mid;
		}

		const double diff = lo * (d - lo) - d;
		const double eps = 1e-7;
		if (abs(diff) < eps)
			cout << "Y " << lo << ' ' << d - lo << '\n';
		else
			cout << "N\n";
	}
	return 0;
}