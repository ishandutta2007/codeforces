#include <iostream>

using namespace std;

int a[1005][1005];
int main()
{
	int n, m, ans = 0;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i ++)
	{
		bool b = false;
		for(int j = 0; j < m; j ++)
		{
			if(a[i][j] == 1)
			{
				b = true;
			}
			if(a[i][j] == 0 && b)
			{
				ans ++;
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		bool b = false;
		for(int j = m; j >= 0; j --)
		{
			if(a[i][j] == 1)
			{
				b = true;
			}
			if(a[i][j] == 0 && b)
			{
				ans ++;
			}
		}
	}
	for(int j = 0; j < m; j ++)
	{
		bool b = false;
		for(int i = 0; i < n; i ++)
		{
			if(a[i][j] == 1)
			{
				b = true;
			}
			if(a[i][j] == 0 && b)
			{
				ans ++;
			}
		}
	}
	for(int j = 0; j < m; j ++)
	{
		bool b = false;
		for(int i = n; i >= 0; i --)
		{
			if(a[i][j] == 1)
			{
				b = true;
			}
			if(a[i][j] == 0 && b)
			{
				ans ++;
			}
		}
	}
	cout << ans;
}