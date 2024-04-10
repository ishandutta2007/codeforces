#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int dist[10][10];

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	for(int x = 0; x <= 9; x++)
	{
		for(int y = 0; y <= 9; y++)
		{
			for(int i = 0; i <= 9; i++)
				for(int j = 0; j <= 9; j++)
					dist[i][j] = 1e9;
			for(int d = 0; d <= 9; d++)
			{
				int nxt = (d + x) % 10;
				dist[d][nxt] = 1;
				nxt = (d + y) % 10;
				dist[d][nxt] = 1;
			}
			for(int k = 0; k <= 9; k++)
				for(int i = 0; i <= 9; i++)
					for(int j = 0; j <= 9; j++)
						dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			int ans = 0, prv = 0;
			for(int i = 1; i < s.size(); i++)
			{
				int cur = s[i] - '0';
				if(dist[prv][cur] == 1e9)
				{
					ans = -1;
					break;
				}
				ans += dist[prv][cur];
				prv = cur;
			}
			if(ans == -1)
				cout << ans << " ";
			else
				cout << (ans - (int)s.size() + 1) << " ";
		}
		cout << endl;
	}

	return 0;
}