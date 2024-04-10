#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 25;

int n, m;
int a[N][N];

bool isValid(int x, int y)
{
	if(x == 1 || x == n || y == 1 || y == m)
	{
		for(int i = -1; i <= 1; i++)
		{
			for(int j = -1; j <= 1; j++)
			{
				if(a[x + i][y + j])
					return 0;
			}
		}
		return 1;
	}
	return 0;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(a, 0, sizeof(a));
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(isValid(i, j))
					a[i][j] = 1;
				cout << a[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}