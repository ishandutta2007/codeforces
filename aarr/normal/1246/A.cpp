#include <iostream>
using namespace std;


const int M = 50 * 1000 * 1000, LG = 40;

int get(long long x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < M; i++) {
		long long x = (long long) n - 1ll * p * i;
		if (x >= i && __builtin_popcount(x) <= i) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}