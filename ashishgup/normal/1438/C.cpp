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
			{
				cin >> a[i][j];
				if(a[i][j] % 2 == (i + j) % 2)
					cout << a[i][j] << " ";
				else
					cout << a[i][j] + 1 << " ";
			}
			cout << endl;
		}
	}
	return 0;
}