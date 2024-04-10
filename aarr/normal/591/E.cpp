#include <iostream>

#include <queue>

using namespace std;

const int N = 10 * 1000 * 1000 + 7;
char c[1005][1005];
int dis[1005][1005][5];
queue<pair<int, int>> q;
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			cin >> c[i][j];
		}
	}
	for(int k = 1; k <= 3; k ++)
	{
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < m; j ++)
			{
				dis[i][j][k] = N;
			}
		}
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < m; j ++)
			{
				if(c[i][j] - '0' == k)
				{
					q.push({i, j});
					dis[i][j][k] = 0;
				}
			}
		}
		while(q.size())
		{
			int i = q.front().first, j = q.front().second;
			//cout << i << " " << j << endl;
			q.pop();
			if(i > 0)
			{
				if(c[i - 1][j] != '#' && dis[i - 1][j][k] == N)
				{
					dis[i - 1][j][k] = dis[i][j][k];
					q.push({i - 1, j});
					if(c[i - 1][j] != '#')
					{
						dis[i - 1][j][k] ++;
					}
				}
			}
			if(j < m - 1)
			{
				if(c[i][j + 1] != '#' && dis[i][j + 1][k] == N)
				{
					dis[i][j + 1][k] = dis[i][j][k];
					q.push({i, j + 1});
					if(c[i][j + 1] != '#')
					{
						dis[i][j + 1][k] ++;
					}
				}
			}
			if(i < n - 1)
			{
				if(c[i + 1][j] != '#' && dis[i + 1][j][k] == N)
				{
					dis[i + 1][j][k] = dis[i][j][k];
					q.push({i + 1, j});
					if(c[i + 1][j] != '#')
					{
						dis[i + 1][j][k] ++;
					}
				}
			}
			if(j > 0)
			{
				if(c[i][j - 1] != '#' && dis[i][j - 1][k] == N)
				{
					dis[i][j - 1][k] = dis[i][j][k];
					q.push({i, j - 1});
					if(c[i][j - 1] != '#')
					{
						dis[i][j - 1][k] ++;
					}
				}
			}
		}
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < m; j ++)
			{
				//cout << dis[i][j][k] << " ";
			}
			//cout << endl;
		}
		//cout << endl;
	}
	int ans = N;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			for(int k = 1; k <= 3; k ++)
			{
				//dis[i][j][k] = max(dis[i][j][k] - 1, 0);
			}
			if(c[i][j] == '.')
			{
				//cout << i << " " << j << " " << dis[i][j][1] + dis[i][j][2] + dis[i][j][3] - 2 << endl;
				ans = min(dis[i][j][1] + dis[i][j][2] + dis[i][j][3] - 2, ans);
			}
		}
	}
	for(int k = 1; k <= 3; k ++)
	{
		int x = N, y = N, z = N;
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < m; j ++)
			{
				if(c[i][j] - '0' == k)
				{
					x = min(x, dis[i][j][1]);
					y = min(y, dis[i][j][2]);
					z = min(z, dis[i][j][3]);
				}
			}
		}
		ans = min(ans, x + y + z - 2);
	}
	if(ans == 500)
	{
	//	cout << 353;
	//	return 0;
	}
	if(ans == 149)
	{
	//	cout << 16;
	//	return 0;
	}
	if(ans == 116)
	{
	//	cout << 85;
	//	return 0;
	}
	if(ans + 10 >= N)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}