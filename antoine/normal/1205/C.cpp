#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = 59;
int n;
int a[MxN + 9][MxN + 9];

bool query(const int x1, const int y1, const int x2, const int y2) {
	assert(x1 <= x2 && y1 <= y2);
	assert(x1 + y1 + 2 <= x2 + y2);
	cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	int resp;
	cin >> resp;
	if (resp == 0)
		return false;
	assert(resp == 1);
	return true;
}

void flipOdd() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if ((i + j) % 2)
				a[i][j] ^= 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	// [!] down and right

	memset(a, -1, sizeof a);

	cin >> n;
	a[1][1] = 1;
	a[n][n] = 0;
	a[2][2] = a[1][1] ^ !query(1, 1, 2, 2);
	a[2][1] = 0;
	a[3][2] = a[2][1] ^ !query(2, 1, 3, 2);
	a[1][2] = a[3][2] ^ !query(1, 2, 3, 2);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] != -1)
				continue;
			if (i >= 3)
				a[i][j] = a[i - 2][j] ^ !query(i - 2, j, i, j);
			else if (j >= 3)
				a[i][j] = a[i][j - 2] ^ !query(i, j - 2, i, j);
			else
				assert(false);
		}

	bool ok = false;
	for (int x1 = 1; x1 <= n; ++x1)
		for (int y1 = 1; y1 <= n; ++y1)
			for (int x2 = x1 + 1; x2 <= min(n, x1 + 2) && !ok; ++x2)
				for (int y2 = y1 + 1; y2 <= min(n, y1 + 2); ++y2) {
					if (x2 - x1 + y2 - y1 != 3)
						continue;
					if (a[x1][y1] != a[x2][y2])
						flipOdd();

					assert(a[x1][y1] == a[x2][y2]);

					ok |= a[x1 + 1][y1] == a[x2][y2 - 1];
					ok |= a[x1][y1 + 1] == a[x2 - 1][y2];
					if (ok) {
						if (!query(x1, y1, x2, y2))
							flipOdd();
						break;
					}
				}
	assert(ok);

	cout << "!\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << a[i][j];
		cout << '\n';
	}
	return 0;
}