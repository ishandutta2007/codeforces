#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=505;
int n,m;
int a[N][N];
int b[N][N];
int d[N];
bool in[1000005];
int main()
{
	memset(in,false,sizeof(in));
	for (int u=1;u<=16;u++) 
	{
		d[u]=u*u*u*u;
		in[d[u]]=true;
	}
	scanf("%d%d",&n,&m);
	for (int u=1;u<=n;u++)
	for (int i=1;i<=m;i++)
	scanf("%d",&a[u][i]);
	for (int u=1;u<=n;u++)
	{
		for (int i=1;i<=m;i++)
		{
			if ((u+i)&1) printf("720720 ");
			else printf("%d ",720720-d[a[u][i]]);
		}
		printf("\n");
	}
	return 0;
}