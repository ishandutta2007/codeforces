#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int a[N][N];

int32_t main()
{
	IOS;
	int n, m;
	cin >> n >> m;
	int val = 720720;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if((i + j) % 2)
				cout << val << " ";
			else
				cout << val - a[i][j] * a[i][j] * a[i][j] * a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}