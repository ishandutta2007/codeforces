#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int x, y;
int a[10];
vector<int> dx = {1, 0, -1, -1, 0, 1};
vector<int> dy = {1, 1, 0, -1, -1, 0};

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		for(int i = 0; i < 6; i++)
			cin >> a[i];
		for(int i = 1; i <= 100; i++)
			for(int j = 0; j < 6; j++)
				a[j] = min(a[j], a[(j - 1 + 6) % 6] + a[(j + 1) % 6]);
		int ans = 4e18;
		for(int i = 0; i < 6; i++)
		{
			int rx = x, ry = y;
			int take = 2e9;
			if(dx[i] != 0)
				take = min(take, rx / dx[i]);
			if(dy[i] != 0)
				take = min(take, ry / dy[i]);
			if(take < 0)
				continue;
			rx -= take * dx[i];
			ry -= take * dy[i];
			int curCost = take * a[i];
			int cx = rx, cy = ry;
			for(int j = 0; j < 6; j++)
			{
				int rx = cx, ry = cy;
				int take = 2e9;
				if(dx[j] != 0)
					take = min(take, rx / dx[j]);
				if(dy[j] != 0)
					take = min(take, ry / dy[j]);
				if(take < 0)
					continue;
				rx -= take * dx[j];
				ry -= take * dy[j];
				if(rx == 0 && ry == 0)
					ans = min(ans, curCost + take * a[j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}