/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int h;
	long long n, ans = 0;
	cin >> h >> n;
	bool last = 1;
	for (int i = 0, j = 0; i < h; i++) {
		ans++;
		long long g = pow(2, h - 1 - i);
		bool b = (n <= g), b2 = (last);
		//cout << "!" << b << " " << b2 << "!\n";
		if (b != b2) {
			ans += pow(2, h - i) - 1;
			//cout << "+";
		} else {
			last = !b;
		}
		if (n > g)
			n -= g;
		//cout << ans << " ans n = " << n << " g = " << g << endl;
	}
	cout << ans;
}