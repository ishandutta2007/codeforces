#include <bits/stdc++.h>
using namespace std;
bool vis[100010];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++)
			vis[i] = false;
		while(m--)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			vis[b] = true;
		}
		int rt;
		for(int i = 1; i <= n; i++)
			if(!vis[i])
			{
				rt = i;
				break;
			}
		for(int i = 1; i <= n; i++)
			if(i != rt)
				printf("%d %d\n", i, rt);
	}
	return 0;
}