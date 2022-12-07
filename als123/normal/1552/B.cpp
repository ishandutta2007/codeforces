#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=50005;
int a[N][10];
int n,T;
bool in[N];
int mn[10];
bool check (int x,int y)
{
	int tot=0;
	for (int u=1;u<=5;u++) if (a[x][u]<a[y][u]) tot++;
	return tot>=3;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=5;u++) mn[u]=50005;
		for (int u=1;u<=n;u++)
		for (int i=1;i<=5;i++)
		scanf("%d",&a[u][i]);
		int now=1;
		for (int u=2;u<=n;u++)
		{
			if (check(u,now)) now=u;
		}
		for (int u=1;u<=n;u++) if (now!=u)
		{
			if (check(now,u)==false)
			{
				now=-1;break;
			}
		}
		printf("%d\n",now);
	}
	return 0;
}