#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long ans = (a + b + c) / 2;
		cout << ans << endl;
	}
	return 0;
}