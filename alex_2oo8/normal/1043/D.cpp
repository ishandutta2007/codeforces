#include <bits/stdc++.h>

using namespace std;

const int MX = 100000, MXM = 10;

int a[MXM][MX];
vector<int> nxt[MX];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0, p = -1, x; j < n; j++, p = x) {
			ignore = scanf("%d", &x);
			x--;
			if (p != -1) {
				nxt[p].push_back(x);
			}
			a[i][j] = x;
		}
		nxt[a[i][n - 1]].push_back(-1);
	}
	
	long long ans = 0;
	int len = 1;
	for (int i = 1, p = a[0][0]; i < n; i++) {
		bool ok = true;
		for (int x : nxt[p]) ok = ok && x == a[0][i];
		
		if (ok) {
			len++;
		}
		else {
			ans += len * (len + 1ll) / 2;
			len = 1;
		}
		
		p = a[0][i];
	}
	
	ans += len * (len + 1ll) / 2;
	
	printf("%lld\n", ans);
	
	return 0;
}