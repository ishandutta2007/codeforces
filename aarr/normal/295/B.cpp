#include <iostream>

using namespace std;

int dis[505][505];
int a[505];
int mark[505];
long long anss[505];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			cin >> dis[i][j];
		}
	}
	for(int i = n; i > 0; i --)
	{
		cin >> a[i];
	}
	for(int k = 1; k <= n; k ++)
	{
		long long ans = 0;
		mark[a[k]] = 1;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				dis[i][j] = min(dis[i][j],  dis[i][a[k]] + dis[a[k]][j]);
				if(mark[i] == 1 && mark[j] == 1)
				{
					ans += dis[i][j];
				}
				//cout << dis[i][j] << " ";
				//cout << k << " " << i << " " << j << " " << dis[i][j] << " " << dis[i][a[k]] << " " << dis[a[k]][j] << endl;
			}
			//cout << endl;
		}
		anss[n - k + 1] = ans;
	}
	for(int i = 1; i <= n; i ++)
	{
		cout << anss[i] << " ";
	}
}