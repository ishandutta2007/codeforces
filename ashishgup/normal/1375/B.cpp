#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 305;

int n, m;
int a[N][N];

bool work(int& x, int y)
{
	if(x > y)
		return 0;
	x = y;
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int flag = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cin >> a[i][j];
		}
		flag &= work(a[1][1], 2);
		flag &= work(a[1][m], 2);
		flag &= work(a[n][1], 2);
		flag &= work(a[n][m], 2);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(i == 1 && j == 1)
					continue;
				if(i == n && j == 1)
					continue;
				if(i == 1 && j == m)
					continue;
				if(i == n && j == m)
					continue;
				if(i == 1 || i == n || j == 1 || j == m)
					flag &= work(a[i][j], 3);
				else
					flag &= work(a[i][j], 4);
			}
		}
		if(!flag)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= m; j++)
					cout << a[i][j] << " ";
				cout << endl;
			}
		}
	}
	return 0;
}