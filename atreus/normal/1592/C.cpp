#include<bits/stdc++.h>

#define Would
#define you
#define please

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;

int a[maxn], sub[maxn], dp[maxn], pd[maxn];
vector<int> t[maxn];

bool dfs(int v, int par, int totalXor) {
	sub[v] = a[v];
	dp[v] = false;
	for (auto u : t[v]) {
		if (u != par) {
			if (dfs(u, v, totalXor))
				return true;
			if (dp[u] and dp[v])
				return true;
			dp[v] |= dp[u];
			sub[v] ^= sub[u];
		}
	}
	if (sub[v] == 0 and dp[v])
		return true;
	dp[v] |= (sub[v] == totalXor);
	return false;
}

void solveOne() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		t[i].clear();
	int totalXor = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		totalXor ^= a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	if (totalXor == 0) {
		cout << "YES\n";
		return;
	}
	if (k == 2) {
		cout << "NO\n";
		return;
	}
	cout << (dfs(1, -1, totalXor) ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		solveOne();
	}
	Would you please return 0;
}