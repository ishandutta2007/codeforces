#include<bits/stdc++.h>
using namespace std;
int b[101][101];
int lp[101], rp[101];
vector<int> ans[101];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cin >> b[i][j];
			sort(b[i] + 1, b[i] + m + 1);
			lp[i] = 1, rp[i] = m;
		}
		for (int i = 1; i <= m; i++) {
			int minn = 0x3f3f3f3f, id;
			for (int j = 1; j <= n; j++)
				if (b[j][lp[j]] < minn) minn = b[j][lp[j]], id = j;
			for (int j = 1; j <= n; j++)
				if (j == id) ans[j].push_back(b[j][lp[j]++]);
				else ans[j].push_back(b[j][rp[j]--]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[i][j] << ' ';
			ans[i].clear();
			cout << endl;
		}
	}
}