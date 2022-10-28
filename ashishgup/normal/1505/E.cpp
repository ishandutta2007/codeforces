#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long
 
const int N = 10 * 10;

int n, m;
char a[N][N];
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	int x = 1, y = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	int ans = a[1][1] == '*';
	while(x < n && y < m)
	{
		int rdist = 1e9;
		for(int j = y + 1; j <= m; j++)
		{
			if(a[x][j] == '*')
			{
				rdist = j - y;
				break;
			}
		}
		int ddist = 1e9;
		for(int i = x + 1; i <= n; i++)
		{
			if(a[i][y] == '*')
			{
				ddist = i - x;
				break;
			}
		}
		if(rdist > ddist)
		{
			ans += a[x + 1][y] == '*';
			x++;
		}
		else
		{
			ans += a[x][y + 1] == '*';
			y++;
		}
	}
	while(x < n)
	{
		ans += a[x + 1][y] == '*';
		x++;
	}
	while(y < m)
	{
		ans += a[x][y + 1] == '*';
		y++;
	}
	cout << ans;
	return 0;
}