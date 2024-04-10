#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m;
int row[N], col[N], activeRows = 0, activeCols = 0; //active
int b[N][N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= 100; i++)
		row[i] = col[i] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> b[i][j];
			if(!b[i][j])
				row[i] = 0, col[j] = 0;
		}
	}
	bool flag = 1;
	for(int i = 1; i <= n; i++)
		activeRows += row[i];
	for(int i = 1; i <= m; i++)
		activeCols += col[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(b[i][j])
				flag &= (activeCols && activeRows && (row[i] || col[j]));
		}
	}
	if(flag)
	{
		cout << "YES" << endl;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cout << (row[i] && col[j]) << " ";
			cout << endl;
		}
	}
	else
		cout << "NO" << endl;
	return 0;
}