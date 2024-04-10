#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=1005;
int n,m;
int a[N][N];
int c[N];
int id[N];
bool cmp (int x,int y)	{return c[x]<c[y];}
int L[N][N],R[N][N];
int mx[N][N],mx1[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	scanf("%d",&a[u][i]);
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=m;i++)	c[i]=a[u][i],id[i]=i;
		sort(id+1,id+1+m,cmp);
		int lst=-1,o=0;
		for (int i=1;i<=m;i++)
		{
			int x=id[i];
			if (c[x]!=lst)	{o++;lst=c[x];}
			L[u][x]=o;
		}
		for (int i=1;i<=m;i++) mx[u][i]=o;
	}
	for (int u=1;u<=m;u++)
	{
		for (int i=1;i<=n;i++) c[i]=a[i][u],id[i]=i;
		sort(id+1,id+1+n,cmp);
		int lst=-1,o=0;
		for (int i=1;i<=n;i++)
		{
			int x=id[i];
			if (c[x]!=lst)	{o++;lst=c[x];}
			R[x][u]=o;
		}
		for (int i=1;i<=n;i++) mx1[i][u]=o;
	}
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=m;i++)
		{
			if (L[u][i]>R[u][i])	mx1[u][i]+=(L[u][i]-R[u][i]);
			else mx[u][i]+=(R[u][i]-L[u][i]);
			printf("%d ",max(mx[u][i],mx1[u][i]));
		}
		printf("\n");
	}
	return 0;
}