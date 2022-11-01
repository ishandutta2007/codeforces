/*
	
	What doesn't kill us, only makes us stronger ...

*/

#include <bits/stdc++.h>

using namespace std;

int n, g[60][60];
stack <int> od, ev;

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	memset(g, 0, sizeof g);
	int m = 1 + (n >> 1);

	for (int i = 1; i <= n * n; ++i) {
		if (i & 1) od.push(i);
		else ev.push(i);
	}

	int space = m - 1;
	for (int i = 1; i < m; ++i) {
		int tot = i + i - 1;
		for (int j = 1; j <= tot; ++j) g[i][space + j] = 1;
		space--;
	}

	for (int i = 1; i <= n; ++i) g[m][i] = 1;

	space = 1;
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j <= n; ++j) g[m + i][j] = g[m - i][j];
	}
	
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 1; j <= n; ++j) cout << g[i][j] << " ";
	// 	cout << endl;
	// }

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (g[i][j] & 1) {
				g[i][j] = od.top();
				od.pop();
			} else {
				g[i][j] = ev.top();
				ev.pop();
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cout << g[i][j] << " ";
		cout << endl;
	}
	return 0;
}