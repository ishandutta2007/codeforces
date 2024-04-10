#include<cstdio>
#include<cstring>
int vis[15];
int vis1[15];
int n,m;
int main()
{
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		vis[x]++;
	}
	for (int u=1;u<=m;u++)
	{
		int x;
		scanf("%d",&x);
		vis1[x]++;
	}
	for (int u=1;u<=9;u++)
		if (vis[u]>0&&vis1[u]>0)
		{
			printf("%d\n",u);
			return 0;
		}
	int a,b;
	for (int u=1;u<=9;u++)
		if (vis[u]!=0)
		{
			a=u;
			break;
		}
	for (int u=1;u<=9;u++)
		if (vis1[u]!=0)
		{
			b=u;
			break;
		}
	if (a>b) {int tt=a;a=b;b=tt;}
	if (a==b) printf("%d\n",a);
	else printf("%d\n",a*10+b);
	return 0;
}