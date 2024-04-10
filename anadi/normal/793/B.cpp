#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int inf = 1e9 + 7;

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};

int n, m;
char s[N][N];
bool dp[N][N][4][3];

void dfs(int x, int y, int dir, int ile){
	if(s[x][y] == '*' || ile > 2 || x < 1 || x > n || y < 1 || y > m)
		return;
	if(dp[x][y][dir][ile])
		return;
	dp[x][y][dir][ile] = true;
	
	for(int i = 0; i < 4; ++i)
		dfs(x + DX[i], y + DY[i], i, ile + (i != dir));
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	PII start = {-1, -1}, meta = {-1, -1};
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(s[i][j] == 'S')
				start = {i, j};
			else if(s[i][j] == 'T')
				meta = {i, j};

	for(int i = 0; i < 4; ++i)
		dfs(start.st, start.nd, i, 0);

	bool answer = false;
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 3; ++j)
			answer |= dp[meta.st][meta.nd][i][j];

	if(answer)
		puts("YES");
	else
		puts("NO");
	return 0;
}