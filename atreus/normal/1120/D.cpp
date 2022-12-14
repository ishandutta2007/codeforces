#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

ll dp[maxn], pd[maxn], c[maxn];
vector<int> t[maxn], ans;
bool mark[maxn], candp[maxn], canpd[maxn];

void DFS(int v, int par = -1){
//	cout << v << " -> " << candp[v] << " " << canpd[v] << endl;
	ll sum = 0;
	for (auto u : t[v])
		if (u != par)
			sum += dp[u];
	if (candp[v]){
		bool canIcome = (par != -1 and t[v].size() == 1);
		for (auto u : t[v])
			if (u != par and sum - dp[u] + pd[u] + c[v] == dp[v])
				canIcome = 1;
		if (canIcome)
			ans.push_back(v);
	}

	if (candp[v]){
		int idx = -1;
		for (auto u : t[v]){
			if (u != par and sum - dp[u] + pd[u] + c[v] == dp[v]){
				canpd[u] = 1;
				if (idx > 0)
					idx = -2;
				if (idx == -1)
					idx = u;
			}
		}
		for (auto u : t[v])
			if (u != par and (sum == dp[v] or u != idx))
				candp[u] = 1;
	}
	if (canpd[v]){
		int idx = -1;
		for (auto u : t[v]){
			if (u != par and sum - dp[u] + pd[u] == pd[v]){
				canpd[u] = 1;
				if (idx > 0)
					idx = -2;
				if (idx == -1)
					idx = u;
			}
		}
		for (auto u : t[v])
			if (u != par and u != idx)
				candp[u] = 1;
	}
	for (auto u : t[v])
		if (u != par)
			DFS(u, v);
}

void dfs(int v, int par = -1){
	if (par != -1 and t[v].size() == 1){
		dp[v] = c[v];
		pd[v] = 0;
		return;
	}
	ll sum = 0;
	for (auto u : t[v]){
		if (u != par){
			dfs(u, v);
			sum += dp[u];
		}
	}
	dp[v] = pd[v] = sum;
	for (auto u : t[v]){
		if (u != par){
			dp[v] = min(dp[v], sum - dp[u] + pd[u] + c[v]);
			pd[v] = min(pd[v], sum - dp[u] + pd[u]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int v = 1; v <= n; v++)
		cin >> c[v];
	for (int edge = 1; edge <= n - 1; edge++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	dfs(1);
	candp[1] = 1;
	DFS(1);
	sort(ans.begin(), ans.end());
	cout << dp[1] << " " << ans.size() << endl;
	for (auto it : ans)
		cout << it << " ";
	cout << endl;
}