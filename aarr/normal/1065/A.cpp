#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int s, a, b, c;
		cin >> s >> a >> b >> c;
		int x = s / c;
		cout << 1ll * (x / a) * (a + b) + x % a << endl;
	}
	return 0;
}