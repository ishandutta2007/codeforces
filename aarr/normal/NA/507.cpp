#include <iostream>
using namespace std;

const int N = 2000 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

long long f[N];

int main() {
	f[3] = 4;
	for (int i = 4; i < N; i++) {
		f[i] = (f[i - 1] + f[i - 2] * 2) % mod;
		if (i % 3 == 0) {
			(f[i] += 4) %= mod;
		}
	}
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	
	return 0;
}