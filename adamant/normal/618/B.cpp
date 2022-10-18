// Moscow IPT Hello
#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	int p[n];
	memset(p, 0, sizeof(p));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(p[j])
				continue;
			bool ok = 1;
			for(int k = 0; k < n; k++)
			{
				ok &= a[j][k] <= i;
			}
			if(ok)
			{
				p[j] = i;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++)
		cout << p[i] << " ";
	
	return 0;
}