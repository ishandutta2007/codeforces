#include <iostream>
using namespace std;



int main() {
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int ans = k * l / nl;
	ans = min(ans, c * d);
	ans = min(ans, p / np);
	ans /= n;
	cout << ans;
	return 0;
}