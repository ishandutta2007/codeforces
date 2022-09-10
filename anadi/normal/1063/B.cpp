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

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};
const int COST[] = {0, 1, 1, 0};

int n, m;
char s[N][N];
priority_queue <pair <int, PII> > Q;

int sx, sy;
int ll, lr;
int dist[N][N];

bool exist(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m && s[x][y] == '.';
}

int main(){
	scanf("%d %d", &n, &m);
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &ll, &lr);
	
	for(int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			dist[i][j] = MX + MX;
	dist[sx][sy] = 0;

	Q.push({0, {sx, sy}});
	while(!Q.empty()){
		PII cur = Q.top().nd;
		Q.pop();
		
		int cx = cur.st, cy = cur.nd;
		for(int i = 0; i < 4; ++i){
			int nx = cx + DX[i], ny = cy + DY[i];
			if(exist(nx, ny) && dist[nx][ny] > dist[cx][cy] + COST[i]){
				dist[nx][ny] = dist[cx][cy] + COST[i];
				Q.push({-dist[nx][ny], {nx, ny}});
			}
		}
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j){
			if(dist[i][j] > N * N)
				continue;

			int cntl = (dist[i][j] + sy - j) / 2;
			int cntr = (dist[i][j] + j - sy) / 2;
//			printf("%d %d :: %d -> %d %d\n", i, j, dist[i][j], cntl, cntr);
			
			res += cntl <= ll && cntr <= lr;
		}
	
	printf("%d\n", res);
	return 0;
}