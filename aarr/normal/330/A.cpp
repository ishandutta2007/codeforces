#include <iostream>
using namespace std;

const int N = 15;

char c[N][N];
bool a[N];
bool b[N];

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'S') {
				a[i] = true;
				b[j] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((!a[i] || !b[j]) && c[i][j] == '.') {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}