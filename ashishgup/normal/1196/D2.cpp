#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int r[N][3], g[N][3], b[N][3];
char a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			for(int k = 0; k <= 2; k++)
			{
				r[i][k] = r[i - 1][k];
				g[i][k] = g[i - 1][k];
				b[i][k] = b[i - 1][k];
			}
			if(a[i] != 'R')
				r[i][i % 3]++;
			if(a[i] != 'G')
				g[i][i % 3]++;
			if(a[i] != 'B')
				b[i][i % 3]++;
		}
		int ans = 1e9;
		for(int i = 1; i + k - 1 <= n; i++)
		{
			for(int j = 0; j <= 2; j++)
			{
				int cur = r[i + k - 1][j] - r[i - 1][j];
				cur += g[i + k - 1][(j + 1) % 3] - g[i - 1][(j + 1) % 3];
				cur += b[i + k - 1][(j + 2) % 3] - b[i - 1][(j + 2) % 3];
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
	return 0;
}