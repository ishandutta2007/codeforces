#include <iostream>
using namespace std;

const int N = 1005;

int a[N], b[N];
int main() {
	int n, m, ans = 0, x = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[x] >= b[i]) {
			ans++;
			x++;
		}
	}
	cout << ans;
	return 0;
}