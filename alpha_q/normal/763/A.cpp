#include <bits/stdc++.h> 

using namespace std;

const int N = 1e5 + 10;

bitset <N> vis;
vector <int> g[N];
int n, c[N], flat[N], good[N], p = 0;
int preGood[N], sufGood[N], l[N], r[N];
int done = 0;

void dfs (int u) {
	vis[u] = 1;
	flat[++p] = u;
	l[u] = p;
	good[u] = c[u];
	for (int v : g[u]) {
		if (vis[v]) continue;
		dfs(v);
		if (good[v] == -1) good[u] = -1;
		if (good[u] != -1 and good[v] != good[u]) {
			good[u] = -1;
		}
	}
	r[u] = p;
}

void go (int u, int par) {
	if (done) return;
	int f = 1;
	for (int v : g[u]) {
		if (v == par) continue;
		if (good[v] == -1) {
			f = 0;
		}
		go(v, u);
		if (done) return;
	}
	if (f) {
		int lt = l[u], rt = r[u];
		int flag = 1;
		if (preGood[lt - 1] == 1 and sufGood[rt + 1] == 1) {
			if (lt > 1 and rt < n and c[flat[1]] != c[flat[n]]) {
				flag = 0;
			} 
		} else {
			flag = 0;
		}
		if (flag) {
			done = 1;
			printf("YES\n%d\n", u);
			return;
		}
	}
}

int main (int argc, char const *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", c + i);
	}
	dfs(1);
	preGood[0] = preGood[1] = 1;
	int f = 1;
	for (int i = 2; i <= n; ++i) {
		if (c[flat[i]] != c[1]) {
			f = 0;
		}   
		if (f) preGood[i] = 1;
		else preGood[i] = -1;
	}
	f = 1;
	sufGood[n] = sufGood[n + 1] = 1;
	for (int i = n - 1; i; --i) {
		if (c[flat[i]] != c[flat[n]]) {
			f = 0;
		}
		if (f) sufGood[i] = 1;
		else sufGood[i] = -1;
	}
	// for (int i = 1; i <= n; ++i) {
	// 	cout << preGood[i] << " "; 
	// }
	// cout << endl;
	// for (int i = 1; i <= n; ++i) {
	// 	cout << sufGood[i] << " "; 
	// }
	// cout << endl;
	go(1, -1);
	if (done == 0) puts("NO");
    return 0;
}