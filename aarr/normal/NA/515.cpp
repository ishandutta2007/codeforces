#include <iostream>

using namespace std;

long long dis[305][305];
int main()
{
	int n, k;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= n; j ++)
		{
			cin >> dis[i][j];
		}
	}
	cin >> k;
	for(int ii = 0; ii < k; ii ++)
	{
		int x, y, z;
		long long ans = 0;
		cin >> x;
		cin >> y;
		cin >> z;
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j <= n; j ++)
			{
				dis[i][j] = min(dis[i][j], min(dis[i][x] + z + dis[y][j], dis[i][y] + z + dis[x][j]));
				//cout << dis[i][j] << " ";
				ans += dis[i][j];
			}
			//cout << endl;
		}
		ans /= 2;
		cout << ans << " ";
	}
	return 0;
}