#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long n;
		cin >> n;
		int a, b;
		cin >> a >> b;
		cout << min(n * a, n / 2 * b + n % 2 * a) << endl;
	}
	return 0;
}