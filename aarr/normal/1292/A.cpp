#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

bool b[5][N];
int main() {
	ios :: sync_with_stdio(false);
	int n, q;
	long long cnt = 0;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		if (b[3 - x][y]) {
			if (b[x][y]) {
				cnt--;
			}
			else {
				cnt++;
			}
		}
		if (b[3 - x][y - 1]) {
			if (b[x][y]) {
				cnt--;
			}
			else {
				cnt++;
			}
		}
		if (b[3 - x][y + 1]) {
			if (b[x][y]) {
				cnt--;
			}
			else {
				cnt++;
			}
		}
		b[x][y] ^= 1;
		if (cnt == 0) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}
	}
	return 0;
}