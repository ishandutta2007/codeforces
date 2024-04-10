#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2005;

int n;
int fr[10][N], lr[10][N], fc[10][N], lc[10][N];
char a[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				fr[j][i] = n + 1;
				fc[j][i] = n + 1;
				lr[j][i] = -1;
				lc[j][i] = -1;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
				int cur = a[i][j] - '0';
				fr[cur][i] = min(fr[cur][i], j);
				fc[cur][j] = min(fc[cur][j], i);
				lr[cur][i] = max(lr[cur][i], j);
				lc[cur][j] = max(lc[cur][j], i);
			}
		}
		for(int i = 0; i < 10; i++)
		{
			int ans = 0;
			int mn = n + 1, mx = -1;
			for(int r1 = 1; r1 <= n; r1++)
			{
				for(int r2 = r1; r2 <= n; r2++)
				{
					mn = min(mn, fr[i][r2]);
					mx = max(mx, lr[i][r2]);
					if(lr[i][r1] == -1 && lr[i][r2] == -1)
						continue;
					if(lr[i][r1] == -1)
					{
						ans = max(ans, (r2 - r1) * (lr[i][r2] - mn));
						ans = max(ans, (r2 - r1) * (mx - fr[i][r2]));
					}
					else if(lr[i][r2] == -1)
					{
						ans = max(ans, (r2 - r1) * (lr[i][r1] - mn));
						ans = max(ans, (r2 - r1) * (mx - fr[i][r1]));
					}
					else
					{
						ans = max(ans, (r2 - r1) * (lr[i][r2] - mn));
						ans = max(ans, (r2 - r1) * (mx - fr[i][r2]));
						ans = max(ans, (r2 - r1) * (lr[i][r1] - mn));
						ans = max(ans, (r2 - r1) * (mx - fr[i][r1]));
					}
				}
				if(lr[i][r1] != -1)
					ans = max(ans, (lr[i][r1] - fr[i][r1]) * max(r1 - 1, n - r1));
			}
			mn = n + 1, mx = -1;
			for(int r1 = 1; r1 <= n; r1++)
			{
				for(int r2 = r1; r2 <= n; r2++)
				{
					mn = min(mn, fc[i][r2]);
					mx = max(mx, lc[i][r2]);
					if(lc[i][r1] == -1 && lc[i][r2] == -1)
						continue;
					if(lc[i][r1] == -1)
					{
						ans = max(ans, (r2 - r1) * (lc[i][r2] - mn));
						ans = max(ans, (r2 - r1) * (mx - fc[i][r2]));
					}
					else if(lc[i][r2] == -1)
					{
						ans = max(ans, (r2 - r1) * (lc[i][r1] - mn));
						ans = max(ans, (r2 - r1) * (mx - fc[i][r1]));
					}
					else
					{
						ans = max(ans, (r2 - r1) * (lc[i][r2] - mn));
						ans = max(ans, (r2 - r1) * (mx - fc[i][r2]));
						ans = max(ans, (r2 - r1) * (lc[i][r1] - mn));
						ans = max(ans, (r2 - r1) * (mx - fc[i][r1]));
					}
				}
				if(lc[i][r1] != -1)
					ans = max(ans, (lc[i][r1] - fc[i][r1]) * max(r1 - 1, n - r1));
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}