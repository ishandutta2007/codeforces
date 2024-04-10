#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m;
char a[N][N];
vector<char> store = {'B', 'W'};

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int flag = (n * m) % 2;
		int idx = 0;
 		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if((i % 2) ^ (j % 2))
					a[i][j] = 'W';
				else
					a[i][j] = 'B';
			}
		}
		if((n * m) % 2 == 0)
		{
			int flag = 0;
			for(int i = n; i >= 1; i--)
			{
				if(flag)
					break;
				for(int j = m; j >= 1; j--)
				{
					if(a[i][j] == 'W')
					{
						a[i][j] = 'B';
						flag = 1;
						break;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}