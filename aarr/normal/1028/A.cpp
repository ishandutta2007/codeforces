#include <iostream>
using namespace std;

int main() {
	int n, m, h1 = 1005, w1 = 1005, h2, w2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'B') {
				h1 = min(h1, i);
				w1 = min(w1, j);
				h2 = i;
				w2 = j;
			}
		}
	}
	cout << (h1 + h2) / 2 << " " << (w1 + w2) / 2;
	return 0;
}