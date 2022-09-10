#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1007;
const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};

int n, m, t;
char in[N][N];

int cnt;
int sz[N * N];
int place[N][N];

int dist[N][N];
bool vis[N][N];

bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void dfs(int x, int y){
	vis[x][y] = true;
	sz[cnt]++;
	place[x][y] = cnt;
	
	for(int t = 0; t < 4; ++t){
		int nx = x + DX[t], ny = y + DY[t];
		if(exist(nx, ny) && !vis[nx][ny] && in[nx][ny] == in[x][y])
			dfs(nx, ny);
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &t);
	for(int i = 1; i <= n; ++i)
		scanf("%s", in[i] + 1);
	
	queue <PII> Q;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			if(!vis[i][j]){
				++cnt;
				dfs(i, j);
			}
			
			if(sz[place[i][j]] > 1){
				dist[i][j] = 0;
				Q.push({i, j});
			}
			else{
				dist[i][j] = -1;
				dist[i][j] = -1;
			}
		}
	
	while(!Q.empty()){
		auto p = Q.front();
		Q.pop();
		
		for(int t = 0; t < 4; ++t){
			PII nxt = {p.st + DX[t], p.nd + DY[t]};
			if(exist(nxt.st, nxt.nd) && dist[nxt.st][nxt.nd] == -1){
				dist[nxt.st][nxt.nd] = dist[p.st][p.nd] + 1;
				Q.push(nxt);
			}
		}
	}
	
	while(t--){
		int x, y;
		LL p;

		scanf("%d %d %lld", &x, &y, &p);
		
		if(dist[x][y] == -1)
			printf("%c\n", in[x][y]);
		else if(p <= dist[x][y])
			printf("%c\n", in[x][y]);
		else{
			p -= dist[x][y];
			int ans = in[x][y] - '0';
			ans ^= p & 1;
			printf("%d\n", ans);
		}
	}

	return 0;
}