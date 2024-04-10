#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1005;
const int K = 41;

int n, m, k;
int a[N][N];
int distC[K][K];
int dist[K][N][N];
bool vis[K][N][N];
int dx[4]={-1, +1, 0, 0};
int dy[4]={0, 0, +1, -1};

void bfs(int c)
{
	queue<pair<int, int> > q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == c)
			{
				q.push({i, j});
				vis[c][i][j] = 1;
				dist[c][i][j] = 1;
			}
		}
	}
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(nx<1 || ny<1 || nx>n || ny>m)
				continue;
			if(!vis[c][nx][ny])
			{
				dist[c][nx][ny] = dist[c][x][y]+1;
				vis[c][nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
}


void floydWarshall()
{
	for(int mid = 1; mid <= k; mid++)
	{
		for(int i = 1; i <= k; i++)
		{
			for(int j = 1; j <= k; j++)
			{
				distC[i][j] = min(distC[i][j], distC[i][mid] + distC[mid][j]);
			}
		}
	}
}
 
void precompute()
{
	for(int i = 1; i <= k; i++)
		bfs(i);
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(i != j)
				distC[i][j] = 1e9;
		}
	}
	for(int c = 1; c <= k; c++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				distC[c][a[i][j]] = min(dist[c][i][j], distC[c][a[i][j]]);
				distC[a[i][j]][c] = min(dist[c][i][j], distC[a[i][j]][c]);
			}
		}
	}
	floydWarshall();
}

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	precompute();
	int q;
	cin >> q;
	while(q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = abs(x2 - x1) + abs(y2 - y1);
		for(int c = 1; c <= k; c++)
		{
			for(int c2 = 1; c2 <= k; c2++)
			{
				int cost = dist[c][x1][y1] + dist[c2][x2][y2] + distC[c][c2] - 1;
				ans = min(ans, cost);
			}
		}
		cout << ans << endl;
	}
	return 0;
}