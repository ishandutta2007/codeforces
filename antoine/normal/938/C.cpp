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

using namespace std;


long long f(long long n, long long k) {
	return n*n - (n / k) * (n / k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long t;
	cin >> t;
	while (t-- > 0) {
		long long x;
		cin >> x;
		if (!x) {
			cout << "1 1\n";
			continue;
		}
		bool answered = false;
		for (long long n = 1; f(n, 2) <= x; ++n) {
			long long d = n*n - x;
			if (d < 1) continue;
			long long s = sqrt((double)d);
			if (s*s != d) continue;
			if (n / s != n / (s + 1)) {
				cout << n << ' ' << (n/s) << '\n';
				answered = true;
				break;
			}
		}
		if (!answered) {
			cout << "-1\n";
		}
	}
	return 0;
}