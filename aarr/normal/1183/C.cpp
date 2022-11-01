#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long k, n, a, b;
		cin >> k >> n >> a >> b;
		k -= 1ll * n * b;
		k--;
		if (k < 0)
			cout << -1 << endl;
		else
			cout << min(k / (a - b), n) << endl;
	}
	return 0;
}