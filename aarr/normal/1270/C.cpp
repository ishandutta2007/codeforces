#include <iostream>
using namespace std;

int a[100 * 1000 + 5];
int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		long long s = 0, x = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			s += a[j];
			x ^= a[j];
		}
		long long b = 1ll << 55;
		cout << 2 << '\n';
		s += x;
		
		cout << x << " " << s  << '\n';
	} 
	return 0;
}