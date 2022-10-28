#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, ans = 0;
int a[N][N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int mn = 2e9;
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			mn = min(mn, a[i][j]);
		}
		ans = max(ans, mn);
	}
	cout << ans << endl;
	return 0;
}