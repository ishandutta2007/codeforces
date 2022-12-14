#include <bits/stdc++.h>

using namespace std;

int xx1, yy1, xx2, yy2;

bool dig(int x, int y) {
	cout << "DIG " << x + 1 << " " << y + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

int ask(int x, int y) {
	cout << "SCAN " << x + 1 << " " << y + 1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n = 16, m = 16;
		cin >> n >> m;
		int S1 = ask(0, 0);
		int S2 = ask(0, m - 1);
		int sx = (S1 + S2 - 2 * (m - 1)) / 2;
		int sy = (S1 - S2 + 2 * (m - 1)) / 2;
		int midx = ask(sx/2, 0);
		int xx1 = (S1 - midx) / 2;
		int xx2 = sx - xx1;
		int midy = ask(0, sy/2);
		int yy1 = (S1 - midy) / 2;
		int yy2 = sy - yy1;
		if (dig(xx1, yy1)) {
			dig(xx2, yy2);
		}
		else {
			dig(xx1, yy2);
			dig(xx2, yy1);
		}
	}
}