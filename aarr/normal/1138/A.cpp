#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int l[N][2];
int r[N][2];
int a[N];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]--;
		l[i][0] = l[i - 1][0] + 1;
		l[i][1] = l[i - 1][1] + 1;
		l[i][a[i] ^ 1] = 0;
	}
	for (int i = n; i; i--) {
		r[i][0] = r[i + 1][0] + 1;
		r[i][1] = r[i + 1][1] + 1;
		r[i][a[i] ^ 1] = 0;
	}
	for (int i = 1; i < n; i++) {
		ans = max(ans, min(l[i][0], r[i + 1][1]));
		ans = max(ans, min(l[i][1], r[i + 1][0]));
	}
	cout << ans * 2;
	return 0;
}