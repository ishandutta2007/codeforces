#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 55;
 
int n;
int a[N][N], ans[N];
int row[N][N], col[N][N];
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			row[i][a[i][j]]++;
			col[j][a[i][j]]++;
		}
	}
	for(int i = 1; i <= n - 1; i++)
	{
		int reqd = (n - i);
		for(int j = 1; j <= n; j++)
			if(row[j][i] == reqd && col[j][i] == reqd)
				ans[j] = i;
	}
	bool flag = 1;
	for(int i = 1; i <= n; i++)
	{
		if(ans[i] == n - 1 && flag)
		{
			flag = 0;
			ans[i] = n;
		}
		cout << ans[i] << " ";
	}
	return 0;
}