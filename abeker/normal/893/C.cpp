#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, M;
int cost[MAXN];
vector <int> E[MAXN];
bool bio[MAXN];

int dfs(int x) {
	bio[x] = true;
	int res = cost[x];
	for (auto it : E[x])
		if (!bio[it])
			res = min(res, dfs(it));
	return res;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", cost + i);
	
	while (M--) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	ll sol = 0;
	for (int i = 1; i <= N; i++)
		if (!bio[i])
			sol += dfs(i);
	
	printf("%lld\n", sol);
	
	return 0;
}