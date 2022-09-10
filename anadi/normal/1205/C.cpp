#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 57;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

const int DX[] = {-2, -1, 0, 0, 1, 2};
const int DY[] = {0, -1, -2, 2, 1, 0};

int n;
int ans[N][N];

int ask(int sx, int sy, int ex, int ey){
	if(sx + sy > ex + ey)
		swap(sx, ex), swap(sy, ey);

	printf("? %d %d %d %d\n", sx, sy, ex, ey);
	fflush(stdout);

	int ret;
	scanf("%d", &ret);
	return ret;
}

bool ok(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int x, int y){
	for(int t = 0; t < 6; ++t){
		int nx = x + DX[t], ny = y + DY[t];
		if(ok(nx, ny) && ans[nx][ny] == -1){
			ans[nx][ny] = ans[x][y] ^ 1 ^ ask(x, y, nx, ny);
			dfs(nx, ny);
		}
	}
}

void solve(int a){
	if(ans[a + 1][a + 1] != ans[a][a + 2]){
		if(ask(a, a, a + 1, a + 2))
			ans[a + 1][a + 2] = ans[a][a];
		else
			ans[a + 1][a + 2] = ans[a][a] ^ 1;

		dfs(a + 1, a + 2);
		return;
	}
	
	if(ans[a + 1][a + 1] != ans[a + 2][a]){
		ans[a + 2][a + 1] = ans[a][a] ^ 1 ^ ask(a, a, a + 2, a + 1);
		dfs(a + 2, a + 1);
		return;
	}
	
	if(ans[a + 1][a + 1] == ans[a][a]){
		if(ask(a, a, a + 1, a + 2)){
			ans[a + 1][a + 2] = ans[a][a];
			dfs(a + 1, a + 2);
			return;
		}
		
		if(ask(a, a + 1, a + 2, a + 2)){
			ans[a][a + 1] = ans[a + 2][a + 2];
			dfs(a + 2, a + 2);
			return;
		}
		
		ans[a + 1][a + 2] = ans[a][a] ^ 1;
		dfs(a + 1, a + 2);
		return;
	}
	
	if(ask(a, a, a + 1, a + 2)){
		ans[a + 1][a + 2] = ans[a][a];
		dfs(a + 1, a + 2);
		return;
	}
		
	if(ask(a, a + 1, a + 2, a + 2)){
		ans[a][a + 1] = ans[a + 2][a + 2];
		dfs(a + 2, a + 2);
		return;
	}
		
	ans[a][a + 1] = ans[a][a];
	dfs(a, a + 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			ans[i][j] = -1;
	ans[1][1] = 1, ans[n][n] = 0;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j){
			if((i + j) == 2 || (i + j) == 2 * n || ((i + j) & 1))
				continue;
			
			if(i >= 3)
				ans[i][j] = ans[i - 2][j] ^ 1 ^ ask(i - 2, j, i, j);
			else if(j >= 3)
				ans[i][j] = ans[i][j - 2] ^ 1 ^ ask(i, j - 2, i, j);
			else
				ans[i][j] = ans[i - 1][j - 1] ^ 1 ^ ask(i - 1, j - 1, i, j);
		}
	
	int good = -1;
	for(int i = 1; i + 2 <= n; ++i)
		if(ans[i][i] == 1 && ans[i + 2][i + 2] == 0)
			good = i;
	assert(good != -1);
	
	solve(good);
	puts("!");
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			printf("%d", ans[i][j]);
		puts("");
	}
	
	return 0;
}