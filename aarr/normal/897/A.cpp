#include <iostream>
using namespace std;

int main() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		char c1, c2;
		cin >> c1 >> c2;
		for (int j = l - 1; j <= r - 1; j++) {
			if (s[j] == c1)
				s[j] = c2;
		}
	}
	cout << s;
	return 0;
}