#include <bits/stdc++.h>

const int maxn=107;

using namespace std;

int n,m,cnt;
int a[maxn],b[maxn],c[maxn];
int ma[maxn],hp[maxn],id[maxn],ans[maxn],vis[maxn];

void prework()
{
	for (int i=1;i<=m;i++)
	{
		hp[b[i]]=c[i];
		id[b[i]]=i;
		vis[i]=0;
	}
	for (int i=1;i<=n;i++) ma[i]=a[i];
	cnt=0;
}

void solvel(int k)
{
	for (int i=k;i>0;i--)
	{
		if (!id[i]) continue;
		int flag2=1;
		int now=hp[i];
		for (int j=i;j<=k;j++)
		{
			now+=ma[j];
			if (now<0)
			{
				flag2=0;
				break;
			}
		}
		if (flag2)
		{
			if (!vis[id[i]])
			{
				ans[++cnt]=id[i];
				vis[id[i]]=1;
			}
			for (int j=i;j<=k;j++)
			{
				ma[j]=0;
				if ((id[j]) && (!vis[id[j]]))
				{
					ans[++cnt]=id[j];
					vis[id[j]]=1;
				}
			}
		}
	}
}

void solver(int k)
{
	for (int i=k;i<=n;i++)
	{
		if (!id[i]) continue;
		int flag2=1;
		int now=hp[i];
		for (int j=i;j>=k;j--)
		{
			now+=ma[j];
			if (now<0)
			{
				flag2=0;
				break;
			}
		}
		if (flag2)
		{
			if (!vis[id[i]])
			{
				ans[++cnt]=id[i];
				vis[id[i]]=1;
			}
			for (int j=i;j>=k;j--)
			{
				ma[j]=0;
				if ((id[j]) && (!vis[id[j]]))
				{
					ans[++cnt]=id[j];
					vis[id[j]]=1;
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&b[i],&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int flag1=0;
	for (int k=1;k<=n;k++)
	{
		
		prework();
		solvel(k);
		solver(k);
		if (cnt==m)
		{
			flag1=1;
			printf("%d\n",k);
			for (int i=1;i<=m;i++) printf("%d ",ans[i]);
			printf("\n");
			break;
		}
		prework();
		solver(k);
		solvel(k);
		if (cnt==m)
		{
			flag1=1;
			printf("%d\n",k);
			for (int i=1;i<=m;i++) printf("%d ",ans[i]);
			printf("\n");
			break;
		}
	}
	if (!flag1) printf("-1\n");
}