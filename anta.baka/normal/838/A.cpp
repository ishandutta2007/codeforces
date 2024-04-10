#include <bits/stdc++.h>

using namespace std;

int n, m, a[5000][5000], ans = INT_MAX;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
		}
	for(int i = 0; i < 5000; i++)
		for(int j = 0; j < 5000; j++) {
			if(i)
				a[i][j] += a[i - 1][j];
			if(j)
				a[i][j] += a[i][j - 1];
			if(i && j)
				a[i][j] -= a[i - 1][j - 1];
		}
	for(int k = 2; k <= max(n, m); k++) {
		int cur = 0;
		for(int i = k - 1; i - k < n; i += k)
			for(int j = k - 1; j - k < m; j+= k) {
				int cnt = a[i][j] - (i - k >= 0 ? a[i - k][j] : 0) - (j - k >= 0 ? a[i][j - k] : 0) + (i - k >= 0 && j - k >= 0 ? a[i - k][j - k] : 0);
				cur += min(k * k - cnt, cnt);
			}
		ans = min(ans, cur);
	}
	cout << ans;
}