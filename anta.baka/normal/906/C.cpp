#include <bits/stdc++.h>
using namespace std;

int n, m, e[22];
bool dp[1 << 22];

int main() {
	cin >> n >> m;
	if(n * (n - 1) / 2 == m) return cout << 0, 0;
	for(int i = 0; i < n; i++) e[i] |= (1 << i);
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		e[u] |= (1 << v); e[v] |= (1 << u);
	}
	for(int i = 0; i < n; i++) dp[1 << i] = true;
	int optmask, opt = n + 1;
	for(int mask = 1; mask < (1 << n); mask++) {
		if(!dp[mask]) continue;
		int cov = 0, cnt = 0;
		for(int i = 0; i < n; i++)
			if(mask & (1 << i)) {
				cov |= e[i];
				cnt++;
			}
		if(cov == (1 << n) - 1 && cnt < opt) {
			opt = cnt;
			optmask = mask;
		}
		for(int i = 0; i < n; i++)
			if(cov & (1 << i) && (mask & (1 << i)) == 0)
				dp[mask | (1 << i)] = true;
	}
	cout << opt << '\n';
	for(int i = 0; i < n; i++) if(optmask & (1 << i)) cout << i + 1 << ' ';
}