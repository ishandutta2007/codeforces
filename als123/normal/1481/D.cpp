#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1005;
int T;
int n,m;
char ss[N][N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int u=1;u<=n;u++)	scanf("%s",ss[u]+1);
		int x=-1,y,z;
		for (int u=1;u<=n;u++)
		for (int i=u+1;i<=n;i++)
		if (ss[u][i]==ss[i][u])
		{x=u;y=i;break;}
		if (x!=-1)
		{
			printf("YES\n");
			for (int u=1;u<=m+1;u++)
			{
				if (u&1) printf("%d ",x);
				else printf("%d ",y);
			}
			printf("\n");
			continue;
		}
		for (int u=1;u<=n;u++)
		{
			int A=-1,B=-1;
			for (int i=1;i<=n;i++)
			{
				if (ss[u][i]=='a') A=i;
				if (ss[u][i]=='b') B=i;
			}
			if (A!=-1&&B!=-1) 	{x=A;y=u;z=B;break;}
		}
		if (m&1)
		{
			printf("YES\n");
			for (int u=1;u<=m+1;u++)
			{
				if (u&1) printf("1 ");
				else printf("2 ");
			}
			printf("\n");
		}
		else
		{
			if (x==-1)
			{
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			m/=2;
			if (m&1)
			{
				for (int u=1;u<=m+1;u++)
				{
					if (u&1) printf("%d ",x);
					else printf("%d ",y);
				}
				for (int u=1;u<=m;u++)
				{
					if (u&1) printf("%d ",z);
					else printf("%d ",y);
				}
				printf("\n");
			}
			else
			{
				for (int u=0;u<=m*2;u++)
				{
					if (u%4==0) printf("%d ",y);
					if (u%4==1) printf("%d ",z);
					if (u%4==2) printf("%d ",y);
					if (u%4==3) printf("%d ",x);
				}
				printf("\n");
			}
		}
	}
	return 0;
}