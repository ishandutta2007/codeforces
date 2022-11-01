#include<bits/stdc++.h>
using namespace std;
int p[501];
int ans[501][501];
int st[501];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) {
		int x = i, y = i, maxn = i, c = p[i];
		while (p[i]--) {
			ans[x][y] = c;
			if (st[x] < y-1) --y;
			else st[x] = maxn, maxn = y, ++x;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
}