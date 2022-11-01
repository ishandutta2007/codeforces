#include<bits/stdc++.h>
using namespace std;
int f[5001][5001];
int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int u = a[i-1], v = b[j-1];
			f[i][j] = max(f[i-1][j], f[i][j-1])-1;
			if (u == v) f[i][j] = max(f[i][j], max(0, f[i-1][j-1]) + 2);
			ans = max(ans, f[i][j]);
		}
	cout << ans << endl;
}