#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

const int DX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int DY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n;
int sx, sy;
bool vis[N][N];
bool bad[N][N];

bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int x, int y){
	vis[x][y] = true;
	for(int i = 0; i < 8; ++i){
		int nx = x + DX[i], ny = y + DY[i];
		if(exist(nx, ny) && !bad[nx][ny] && !vis[nx][ny])
			dfs(nx, ny);
	}
}

int main(){
	scanf("%d", &n);
	scanf("%d %d", &sx, &sy);
	
	for(int i = 0; i < 8; ++i)
		for(int t = 0; true; ++t)
			if(exist(sx + DX[i] * t, sy + DY[i] * t))
				bad[sx + DX[i] * t][sy + DY[i] * t] = true;
			else
				break;
	
	scanf("%d %d", &sx, &sy);
	dfs(sx, sy);
	
	scanf("%d %d", &sx, &sy);
	if(vis[sx][sy])
		puts("YES");
	else
		puts("NO");
	return 0;
}