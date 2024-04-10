#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, m;
int a[N][N], b[N][N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> b[i][j];
	for(int i = 1; i <= n; i++)
	{
		int cur = 0;
		for(int j = 1; j <= m; j++)
			cur ^= (a[i][j] != b[i][j]);
		if(cur)
		{
			cout << "No";
			exit(0);
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int cur = 0;
		for(int j = 1; j <= n; j++)
			cur ^= (a[j][i] != b[j][i]);
		if(cur)
		{
			cout << "No";
			exit(0);
		}
	}
	cout << "Yes";
	return 0;
}