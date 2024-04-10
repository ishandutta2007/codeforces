#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5, LG = 18;
int ans;

int a[N];
pair <int, int> dp[5 * N][LG];
int b[N];
int get(int l, int r) {
	int d = r - l;
	int x = 31 - __builtin_clz(d);
//	cout << "73 " << l << " " << r << " " << x << endl;
	return max(dp[l][x], dp[r - (1 << x)][x]).second;
}
void ad(int l, int r) {
	if (r - l <= 1)
		return;
	int m = get(l, r);
//	cout << l << " " << m << " " << r << " " << ans << endl;
	int x = a[m];
//	if (m > l + 1) {
	ad(l, m);
//	}
//	if (m < r - 1) {
	ad(m + 1, r);
//	}
	if (r - m < m - l) {
		for (int i = m + 1; i < r; i++) {
			int y = a[m] - a[i];
			if (b[y] < m && b[y] >= l) {
				ans++;
			}
		}
	}
	else {
		for (int i = l; i < m; i++) {
			int y = a[m] - a[i];
			if (b[y] < r && b[y] > m) {
				ans++;
			}
		}		
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dp[i][0].first;
		a[i] = dp[i][0].first;
		dp[i][0].second = i;
		b[a[i]] = i;
	}
	for (int j = 1; j < LG; j++) {
		for (int i = 0; i < n; i++) {
		//	dp[i][j] = dp[i][j - 1];
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}
	//cout << dp[0][2].first << endl;
	ad(0, n);
	//cout << get(0, 5) << endl;
	cout << ans;
	return 0;
}