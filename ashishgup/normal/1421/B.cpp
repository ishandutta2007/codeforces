#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 205;

int n;
char a[N][N];

void check(int x, int y, char ch)
{
	if(a[x][y] == ch)
		cout << x << " " << y << endl;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> a[i][j];
		int ct0 = 0, ct1 = 0;
		ct0 += (a[1][2] == '0');
		ct0 += (a[2][1] == '0');
		ct0 += (a[n][n - 1] == '1');
		ct0 += (a[n - 1][n] == '1');
		if(ct0 >= 2)
		{
			cout << 4 - ct0 << endl;
			check(1, 2, '1');
			check(2, 1, '1');
			check(n, n - 1, '0');
			check(n - 1, n, '0');
		}
		else
		{
			cout << ct0 << endl;
			check(1, 2, '0');
			check(2, 1, '0');
			check(n, n - 1, '1');
			check(n - 1, n, '1');
		}
	}
	return 0;
}