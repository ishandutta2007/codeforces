#include <bits/stdc++.h>
using namespace std;
int b[100001];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++)
			b[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			b[x % m]++;
		}
		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			if(i * 2 > m)
				break;
			if(i * 2 == m || i == 0)
				ans += (b[i] > 0);
			else
			{
				int x = b[i], y = b[m - i];
				if(x < y)
					swap(x, y);
				if(x == 0 && y == 0);
				else if(x == y)
					ans++;
				else
					ans += (x - y);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}