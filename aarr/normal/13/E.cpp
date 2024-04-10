#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5, SQ = 277;

int a[N];
int dp1[N];
int dp2[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i + a[i] >= n || (i + a[i]) / SQ > i / SQ) {
			dp1[i] = i;
			dp2[i] = 1;
		}
		else {
			dp1[i] = dp1[i + a[i]];
			dp2[i] = dp2[i + a[i]] + 1;
		}
	}
//	for (int i = 0; i < n; i++) {
//		cout << i << " " << dp1[i] << " " << dp2[i] << endl;
//	}
	for (int i = 1; i <= m; i++) {
		int qt, x;
		cin >> qt >> x;
		x--;
		if (qt == 1) {
			int ans = 0;
			while (1) {
				ans += dp2[x];
				x = dp1[x];
				if (dp1[x] < x) {
					int y = 0;
					x /= y;
				}
			//	cout << "74 " << x << endl;
				if (x + a[x] >= n) {
					break;
				}
				x = x + a[x];
			//	cout << "73 " << x << endl;
			//	ans++;
			}
			cout << x + 1 << " " << ans << '\n';
		}
		else {
			int c;
			cin >> c;
			a[x] = c;
			for (int j = x; j / SQ == x / SQ && j >= 0; j--) {
				if (j + a[j] >= n || (j + a[j]) / SQ > j / SQ) {
					dp1[j] = j;
					dp2[j] = 1;
				}
				else {
					dp1[j] = dp1[j + a[j]];
					dp2[j] = dp2[j + a[j]] + 1;
				}
			}
			
		}
	}
	return 0;
}