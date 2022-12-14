/**
 *    author:  Atreus
 *    created: 15.01.2019 18:42:21     
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;

int a[maxn];
vector <int> t[maxn];
int check_bs;

int dp[maxn], st[maxn], sz[maxn], allone[maxn];

int n, cnt;

void dfs(int v, int par = -1){
	bool me = (a[v] >= check_bs);
	allone[v] = me;
	sz[v] = 1;

	int tmp = 0;
	int maxst1 = 0, maxst2 = 0;
	for (auto u : t[v]){
		if (u != par){
			dfs(u, v);
			allone[v] += allone[u];
			sz[v] += sz[u];

			dp[v] = max(dp[v], dp[u]);
			if (allone[u] == sz[u])
				tmp += sz[u];
			else{
				maxst2 = max(maxst2, st[u]);
				if (maxst1 < maxst2)
					swap(maxst1, maxst2);
			}
		}
	}
	if (me == false)
		return;
	if (allone[v] == sz[v])
		dp[v] = st[v] = sz[v];
	else{
		dp[v] = max(dp[v], maxst1 + maxst2 + tmp + 1);
		st[v] = maxst1 + tmp + 1;
		if (n - sz[v] == cnt - allone[v])
			dp[v] = max(dp[v], maxst1 + maxst2 + tmp + 1 + n - sz[v]);
	}
}

int k;

bool check(int x){
	check_bs = x;
	memset(dp, 0, sizeof dp);
	memset(st, 0, sizeof st);
	cnt = 0;
	for (int v = 1; v <= n; v++)
		cnt += (a[v] >= x);
	dfs(1);
	return dp[1] >= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int v = 1; v <= n; v++)
		cin >> a[v];
	for (int ed = 1; ed <= n - 1; ed++){
		int v, u;
		cin >> v >> u;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	int lo = 1, hi = 1000001;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (check(mid) == true)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
	return 0;
}