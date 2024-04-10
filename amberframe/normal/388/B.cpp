#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
const int maxn = 1005;
int e[maxn][maxn],n,w,d[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("path.in","r",stdin);
		freopen("path.out","w",stdout);
	#endif
	scanf("%d",&w);n=2;
	d[0]=++n;e[n][2]=1;
	for (int i=1;i<=60;i++)
		d[i]=++n,e[d[i]][d[i-1]]=1;
	for (int o=1,i=0;i<30&&w;i++)
	{
		if (w&1)
			e[o][d[60-i*2]]=1;
		int u=++n,v=++n;e[o][u]=e[o][v]=1;
		o=++n;w>>=1;e[u][o]=e[v][o]=1;
	}
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		e[i][j]|=e[j][i];
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%c",e[i][j]?'Y':'N');
		puts("");
	}
	return 0;
}