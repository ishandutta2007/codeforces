#include <iostream>
using namespace std;

const int N = 1005;
const int mod = 1000 * 1000 * 1000 + 7;

int a[N][N];
int r[N];
int c[N];
int main() {
	bool b = true;
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		cin >> r[i];
		for (int j = 1; j <= r[i]; j++) {
			a[i][j] = 1;
		}
		a[i][r[i] + 1] = 2;
	}
	for (int j = 1; j <= m; j++) {
		cin >> c[j];
		for (int i = 1; i <= c[j]; i++) {
			if (a[i][j] == 2)
				b = false;
			else
				a[i][j] = 1;
		}
		if (a[c[j] + 1][j] == 1)
			b = false;
		else
			a[c[j] + 1][j] = 2;
	}
	if (!b)
		cout << 0 << endl;
	else {
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 0) {
					ans *= 2;
					ans %= mod;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}