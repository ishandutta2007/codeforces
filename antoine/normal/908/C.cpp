#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
double r;
double x[1000];
double y[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> r;
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	for (int i = 0; i < n; ++i) {
		y[i] = r;
		for (int j = 0; j < i; ++j) {
			auto diff = std::abs(x[j] - x[i]);
			if (diff - 1e-10 <= 2 * r)
				y[i] = max(y[i], y[j] + sqrt(4 * r*r - diff*diff));
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i)
			cout << ' ';
		cout << setprecision(10) << y[i];
	}

	return 0;
}