#include <iostream>
using namespace std;


const int N = 300 * 1000 + 5;

int a[N];
bool mark[N];
int c[N];
int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	long long ans = 0;
	long long x = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i > 0; i--) {
		int y = a[i] - a[i + 1];
		ans += 1ll * y * (i / 2);
		if (i % 2 == 1) {
			for (int j = a[i + 1] + 1; j <= a[i]; j++) {
				mark[j] = true;
				c[j % 2]++;
			}
		}
	}
//	cout << ans << endl;
/*	for (int i = 1; i < N - 2; i++) {
		if (mark[i] && mark[i + 1]) {
			mark[i] = false;
			mark[i + 1] = false;
			ans++;
		}
	}*/
	cout << ans + min(c[0], c[1]) << endl;
	return 0;
}