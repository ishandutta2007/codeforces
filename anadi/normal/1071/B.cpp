#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, k;
char s[N][N];
int dp[N][N];
vector <PII> ok[N + N];

bool marked[N][N];
vector <PII> cur, nxt;

bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (s[i][j] == 'a');
//			printf("%d %d %d\n", i, j, dp[i][j]);
			if(i + j - 1 <= dp[i][j] + k)
				ok[i + j].push_back({i, j});
		}
	
	int t = 0;
	for(int i = n + n; i >= 0; --i)
		if(ok[i].size()){
			t = i;
			break;
		}
	
	for(int i = 1; i < t; ++i)
		printf("%c", 'a');
	
	cur = ok[t];
	if(cur.size() == 0){
		printf("%c", s[1][1]);
		cur.push_back({1, 1});
	}
	
	for(auto v: cur)
		marked[v.st][v.nd] = true;

	while(!marked[n][n]){
		char best = 'z';
		for(auto v: cur){
			int x = v.st, y = v.nd;
			if(exist(x + 1, y) && s[x + 1][y] < best)
				best = s[x + 1][y];
			if(exist(x, y + 1) && s[x][y + 1] < best)
				best = s[x][y + 1];
		}
		
		printf("%c", best);
		for(auto v: cur){
			int x = v.st, y = v.nd;
			if(!marked[x + 1][y] && s[x + 1][y] == best)
				marked[x + 1][y] = true,
				nxt.push_back({x + 1, y});

			if(!marked[x][y + 1] && s[x][y + 1] == best)
				marked[x][y + 1] = true,
				nxt.push_back({x, y + 1});
		}
		
		cur = nxt;
		nxt.clear();
	}

	return 0;
}