#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 105;

int N, M;
vector <pii> E[MAXN];
int dp[MAXN][MAXN][30];

int solve(int a, int b, int last) {
	int &ref = dp[a][b][last];
	if (ref != -1)
		return ref;
	
	for (auto it : E[a])
		if (it.second >= last && solve(b, it.first, it.second))
			return ref = 0;
			
	return ref = 1;  
}

int main() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int u, v;
		char c;
		scanf("%d%d %c", &u, &v, &c);
		E[u].push_back({v, c - 'a'});
	}
	
	memset(dp, -1, sizeof dp);
	
	for (int i = 1; i <= N; i++, puts(""))
		for (int j = 1; j <= N; j++)
			printf("%c", 'A' + solve(i, j, 0));
	
	return 0;
}