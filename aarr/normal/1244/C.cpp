#include <iostream>
using namespace std;


const int N = 60 * 1000 * 1000;
long long bmm(long long x, long long y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
int main() {
	long long n, p, w, d;
	cin >> n >> p;
	cin >> w >> d;
	long long x = 0, y = 0, z = 0;
	if (p % bmm(w , d) != 0) {
		cout << -1;
		return 0;
	}
//	if (w < N) {
		long long a = p / (w * d);
//		x += (a - 1) * d;
		if (x > n) {
			cout << -1 << endl;
			return 0;
		}
		if (a >= 1) {
			x += (a - 1) * d;
			p %= w * d;
			p += w * d;
		}
//		cout << p << " " << x << endl;
		for (int i = p / w + 1; i >= 0; i--) {
			if (p - i * w >= 0 && (p - i * w) % d == 0) {
				x += i;
				y = (p - i * w) / d;
				if (x + y <= n) {
					cout << x << " " << y << " " << n - x - y << endl;
				}
				else {
					cout << -1 << endl;
				}
				return 0;
			}
		}
		cout << -1 << endl;
//	}
	return 0;
}