#include <bits/stdc++.h>

using namespace std;
int n;
int a[200200];
int ans[200200];
int cnt[200200];
vector<int> g[200200];
vector<int> ord;
int P[200200];
void dfs(int v, int p) {
	ord.push_back(v);
	for(int to: g[v]) {
		if(to != p) {
			dfs(to, v);
			P[to] = v;
		}
	}
}
int T;
int good[200200];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	for(int x: ord) {
		if(x == 1) continue;
		ans[x] = __gcd(ans[P[x]], a[x]);
	}
	for(int i = 1; i <= a[1]; i++) {
		if(a[1] % i == 0) {
			T++;
			for(int j = i; j < 200200; j+=i) good[j] = T;
			for(int x: ord) {
				if(good[a[x]] == T) {
					cnt[x] = cnt[P[x]];
				} else {
					cnt[x] = cnt[P[x]]+1;
				}
				if(cnt[x] <= 1) {
					ans[x] = max(ans[x], i);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}