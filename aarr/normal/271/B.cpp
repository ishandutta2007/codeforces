#include <iostream>

using namespace std;

int a[505][505];
int b[505][505];
bool prim[100105];
int main()
{
	prim[1] = false;
	int n, m;
	int s = 1000000000;
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	for(int i = 2; i <= 100100; i ++)
	{
		prim[i] = true;
		for(int j = 2; j * j <= i; j ++)
		{
			if(i % j == 0)
			{
				prim[i] = false;
				break;
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		int x = 0;
		for(int j = 0; j < m; j ++)
		{
			while(prim[a[i][j]] == false)
			{
				a[i][j] ++;
				x ++;
			}
		}
		s = min(s, x);
	}
	for(int j = 0; j < m; j ++)
	{
		int x = 0;
		for(int i = 0; i < n; i ++)
		{
			while(prim[b[i][j]] == false)
			{
				b[i][j] ++;
				x ++;
			}
		}
		s = min(s, x);
	}
	cout << s;
	return 0;
}