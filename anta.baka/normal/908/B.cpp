#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	char a[n][m];
	int i0, j0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S') i0 = i, j0 = j;
		}
	string s; cin >> s;
	int p[] = {0, 1, 2, 3};
	int di[] = {0, 0, 1,-1};
	int dj[] = {1,-1, 0, 0};
	int ans = 0;

	do {
		bool ok = false;
		int i = i0, j = j0;
		for(char x : s) {
			i += di[p[x - '0']];
			j += dj[p[x - '0']];
			if(i == -1 || j == -1 || i == n || j == m || a[i][j] == '#') {
				ok = false;
				break;
			}
			if(a[i][j] == 'E') {
				ok = true;
				break;
			}
		}
		ans += ok;
	} while(next_permutation(p, p + 4));
	cout << ans;
}