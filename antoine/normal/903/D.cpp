#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	long double n;
	cin >> n;
	vector<long double> a(n);
	for (long double i = 0; i < n; ++i)
		cin >> a[i];

	long double ans = 0;
	long double sum = 0;
	map<long double, long double> occ;
	for (long double i = n - 1; i >= 0; --i) {
		++occ[a[i]];
		sum += a[i];
		
		ans += sum - (long double)(n - i) * a[i];
		for (auto &&x : { a[i] - 1, a[i] + 1 }) {
			auto it = occ.find(x);
			if (it != occ.end())
				ans -= it->second * (x - a[i]);
		}
	}
	if (ans < 0) {
		cout << "-";
		ans = -ans;
	}
	cout << (unsigned long long)round(ans);
	return 0;
}