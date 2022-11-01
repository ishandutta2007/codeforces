#include <iostream>
#include <iomanip>
using namespace std;

const int N = 2005;

double dp[N][N];
bool a[N];
bool b[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x] = true;
		b[y] = true;
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i])
			x++;
		if (b[i])
			y++;
	}
//	cout << x << " " << y << endl;
	for (int i = n; i >= x; i--) {
		for (int j = n; j >= y; j--) {
			if (i != n || j != n) {
				double s = 0;
				s += (dp[i + 1][j]) * (n - i) * j / n / n;
				s += (dp[i][j + 1]) * i * (n - j) / n / n;
				s += (dp[i + 1][j + 1]) * (n - i) * (n - j) / n / n;
				dp[i][j] = (s + 1) * n * n / (n * n - i * j);
			//	cout << i << " " << j << " " << s << " " << dp[i][j] << endl;
			}
		}
	}
	cout << fixed << setprecision(6);
	cout << dp[x][y];
	return 0;
}