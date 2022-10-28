#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 501;

int n, x;
int a[N];
int cache[N][N][N];

int dp(int idx, int x, int prvVal)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx][x][prvVal];
	if(ans != -1)
		return ans;
	ans = 1e9;
	if(a[idx] >= prvVal)
		ans = min(ans, dp(idx + 1, x, a[idx]));
	if(x >= prvVal && a[idx] > x)
		ans = min(ans, 1 + dp(idx + 1, a[idx], x));
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= 500; j++)
				for(int k = 0; k <= 500; k++)
					cache[i][j][k] = -1;
		int ans = dp(1, x, 0);
		if(ans == 1e9)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}