#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 51;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
char rd[N];
int in[N][N];
int pref[N][N];
int dp[N][N][N][N];

void read(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", rd + 1);
		for(int j = 1; j <= n; ++j){
			in[i][j] = (rd[j] == '#');
			pref[i][j] = in[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
}

int solve(int sx, int ex, int sy, int ey){
	if(ex < sx || ey < sy)
		return 0;
	
	if(pref[ex][ey] - pref[ex][sy - 1] - pref[sx - 1][ey] + pref[sx - 1][sy - 1] == 0)
		return 0;

	if(dp[sx][ex][sy][ey] > 0)
		return dp[sx][ex][sy][ey];
	
	if(pref[sx][ey] - pref[sx - 1][ey] - pref[sx][sy - 1] + pref[sx - 1][sy - 1] == 0)
		return dp[sx][ex][sy][ey] = solve(sx + 1, ex, sy, ey);
		
	dp[sx][ex][sy][ey] = max(ex - sx + 1, ey - sy + 1);
	for(int s = sx; s <= ex; ++s)
		if(pref[s][ey] - pref[s - 1][ey] - pref[s][sy - 1] + pref[s - 1][sy - 1] == 0)
			dp[sx][ex][sy][ey] = min(dp[sx][ex][sy][ey], solve(sx, s - 1, sy, ey) + solve(s + 1, ex, sy, ey));

	for(int s = sy; s <= ey; ++s)
		if(pref[ex][s] - pref[ex][s - 1] - pref[sx - 1][s] + pref[sx - 1][s - 1] == 0)
			dp[sx][ex][sy][ey] = min(dp[sx][ex][sy][ey], solve(sx, ex, sy, s - 1) + solve(sx, ex, s + 1, ey));
	return dp[sx][ex][sy][ey];
}

int main(){
	read();
	printf("%d\n", solve(1, n, 1, n));
	return 0;
}