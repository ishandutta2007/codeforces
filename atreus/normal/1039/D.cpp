/**
 *    author:  Atreus
 *    created: 20.01.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;

vector <int> t[maxn];
int answer[maxn];
pair <int, int> dp[maxn];

void dfs(int v, int k, int par = -1){
	dp[v] = {0, 0};
	int max1 = 0, max2 = 0;
	for (auto u : t[v]){
		if (u != par){
			dfs(u, k, v);
			dp[v].first += dp[u].first;
			max2 = max(max2, dp[u].second);
			if (max2 > max1)
				swap(max1, max2);
		}
	}
	if (max1 + max2 + 1 >= k){
		dp[v].first ++;
		dp[v].second = 0;
	}
	else{
		dp[v].second = max1 + 1;
	}
}

int check(int x){
	dfs(1, x);
	return dp[1].first;
}

void solve(int L, int R, int optl, int optr){
	if (R < L)
		return;
	if (optl == optr){
		for (int i = L; i <= R; i++)
			answer[i] = optl;
		return;
	}
	int mid = (L + R) >> 1;
	answer[mid] = check(mid);
	solve(L, mid - 1, answer[mid], optr);
	solve(mid + 1, R, optl, answer[mid]);
}

int main(){
	memset(answer, -1, sizeof answer);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		t[u].push_back(v);
		t[v].push_back(u);
	}
	solve(1, n, 0, n);
	for (int v = 1; v <= n; v++)
		printf("%d\n", answer[v]);
}