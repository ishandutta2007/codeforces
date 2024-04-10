#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 505;

int n, m;
char a[N][N];
int ans[N][N];
int dx[4] = {0, 0, -1, +1};
int dy[4] = {+1, -1, 0, 0};

int get(int x, int y)
{
	return (x - 1) * m + y;
}

vector<int> g[N * N];

int col[N * N];
bool vis[N * N];

void dfs(int u, int c)
{
	if(vis[u])
	{
		if(col[u] != c)
		{
			cout << "NO" << endl;
		 	exit(0);
		}
		return;
	}
	vis[u] = 1;
	col[u] = c;
	for(auto &it:g[u])
		dfs(it, c ^ 1);
}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] == 'X')
			{
				int ct = 0;
				vector<pair<int, int> > v;
				for(int dir = 0; dir < 4; dir++)
				{
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					if(nx < 1 || nx > n || ny < 1 || ny > m)
						continue;
					if(a[nx][ny] == 'X')
						ct++;
					else
						v.push_back({nx, ny});
				}
				if(v.size() >= 2)
				{
				    int idx = v.size() == 2 ? 1: 2;
					int uu = get(v[0].first, v[0].second);
					int vv = get(v[idx].first, v[idx].second);
					g[uu].push_back(vv);
					g[vv].push_back(uu);
				}
				if(v.size() == 4)
				{
					int uu = get(v[1].first, v[1].second);
					int vv = get(v[3].first, v[3].second);
					g[uu].push_back(vv);
					g[vv].push_back(uu);
				}
				if(ct == 3 || ct == 1)
				{
					cout << "NO" << endl;
					exit(0);
				}
				else if(ct == 4)
					ans[i][j] = 0;
				else if(ct == 0)
					ans[i][j] = 10;
				else
					ans[i][j] = 5;
			}
		}
	}
	for(int i = 1; i <= n * m; i++)
	{
		if(vis[i])
			continue;
		if(g[i].size())
			dfs(i, 0);
	}
}

void print()
{
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!ans[i][j] && a[i][j] != 'X')
				ans[i][j] = 1;
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	check();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(vis[get(i, j)])
			{
				ans[i][j] = col[get(i, j)] ? 4 : 1;
			}
		}
	}
	print();
	return 0;
}