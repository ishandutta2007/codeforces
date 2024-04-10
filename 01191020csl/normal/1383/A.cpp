#include<bits/stdc++.h>
using namespace std;
char a[100010], b[100010];
int vis[21][21];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n >> a + 1 >> b + 1;
		memset(vis, 0, sizeof(vis));
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] > b[i]) {
				puts("-1");
				flag = 0;
				break;
			}
			if (a[i] == b[i]) continue;
			vis[a[i]-'a'][b[i]-'a'] = 1;
		}
		if (!flag) continue;
		int ans = 0;
		for (int i = 0; i < 20; i++) {
			int p = i;
			for (int j = i + 1; j < 20; j++)
				if (vis[i][j]) {
					p = j;
					break;
				}
			if (p == i) continue;
			++ans;
			for (int j = p + 1; j < 20; j++)
				if (vis[i][j]) vis[p][j] = 1;
		}
		cout << ans << endl;
	}
}