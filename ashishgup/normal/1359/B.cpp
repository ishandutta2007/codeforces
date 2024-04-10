#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;
const int M = 1e3 + 5;

int n, m, x, y;
char a[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> x >> y;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		y = min(x * 2, y);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j] == '*')
					continue;
				int k = j;
				while(k + 1 <= m && a[i][k + 1] == '.')
					k++;
				int cnt = (k - j + 1);
				if(cnt % 2)
					ans += x;
				ans += (cnt / 2) * y;
				j = k;
			}
		}
		cout << ans << endl;
	}
	return 0;
}