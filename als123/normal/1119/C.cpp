#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=505;
int n,m;
int a[N][N],b[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	scanf("%d",&a[u][i]);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	scanf("%d",&b[u][i]);
	int cnt;
	for (int u=1;u<=n;u++)
	{
		cnt=0;
		for (int i=1;i<=m;i++)
			if (a[u][i]!=b[u][i]) cnt++;
		if (cnt&1)	{printf("No\n");return 0;}
	}
	for (int u=1;u<n;u++)
	{
		for (int i=1;i<=m;i++)
		{
			if (a[u][i]!=b[u][i])
			{
				a[u+1][i]^=1;
				a[u][i]^=1;
			}
		}
	}
	for (int u=1;u<=m;u++) if (a[n][u]!=b[n][u])
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}