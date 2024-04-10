#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n, m;
int a[N][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				vector<int> v = {a[i][j], a[i][m - j + 1], a[n - i + 1][j], a[n - i + 1][m - j + 1]};
				sort(v.begin(), v.end());
				int val = v[1];
				ans += abs(a[i][j] - val);
				a[i][j] = val;
				ans += abs(a[i][m - j + 1] - val);
				a[i][m - j + 1] = val;
				ans += abs(a[n - i + 1][j] - val);
				a[n - i + 1][j] = val;
				ans += abs(a[i][j] - val);
				a[i][m - j + 1] = val;
			}
		}
		cout << ans << endl;
	}
	return 0;
}