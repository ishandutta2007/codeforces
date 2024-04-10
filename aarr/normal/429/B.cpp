#include <iostream>

using namespace std;
long long a[1005][1005];
long long tl[1005][1005];
long long tr[1005][1005];
long long bl[1005][1005];
long long br[1005][1005];
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			cin >> a[i][j];
		}
	}
	tl[0][0] = 0;
	tr[0][m - 1] = 0;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			if(i > 0)
			{
				tl[i][j] = tl[i - 1][j] + a[i - 1][j];
			}
			if(j > 0)
			{
				tl[i][j] = max(tl[i][j], tl[i][j - 1] + a[i][j - 1]);
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = m - 1; j >= 0; j --)
		{
			if(i > 0)
			{
				tr[i][j] = tr[i - 1][j] + a[i - 1][j];
			}
			if(j < m - 1)
			{
				tr[i][j] = max(tr[i][j], tr[i][j + 1] + a[i][j + 1]);
			}
		}
	}
	bl[n - 1][0] = 0;
	br[n - 1][m - 1] = 0;
	for(int i = n - 1; i >= 0; i --)
	{
		for(int j = 0; j < m; j ++)
		{
			if(i < n - 1)
			{
				bl[i][j] = bl[i + 1][j] + a[i + 1][j];
			}
			if(j > 0)
			{
				bl[i][j] = max(bl[i][j], bl[i][j - 1] + a[i][j - 1]);
			}
		}
	}
	for(int i = n - 1; i >= 0; i --)
	{
		for(int j = m - 1; j >= 0; j --)
		{
			if(i < n - 1)
			{
				br[i][j] = br[i + 1][j] + a[i + 1][j];
			}
			if(j < m - 1)
			{
				br[i][j] = max(br[i][j], br[i][j + 1] + a[i][j + 1]);
			}
		}
	}
	long long x = 0;
	for(int i = 1; i < n - 1; i ++)
	{
		for(int j = 1; j < m - 1; j ++)
		{
			long long y = max(tl[i - 1][j] + tr[i][j + 1] + br[i + 1][j] + bl[i][j - 1], tl[i][j - 1] + tr[i - 1][j] + br[i][j + 1] + bl[i + 1][j]);
			y += a[i - 1][j] + a[i][j + 1] + a[i + 1][j] + a[i][j - 1];
			x = max(x, y);
		}
	}
	cout << x;
	return 0;
}