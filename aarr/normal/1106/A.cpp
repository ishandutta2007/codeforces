#include <iostream>
using namespace std;


int a[505][505];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == 'X')
				a[i][j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] && a[i - 1][j - 1] && a[i - 1][j + 1] && a[i + 1][j - 1] && a[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}