#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005;
const int K=105;
int L[K],R[K];
int n,k;
int f[K][N];
int q[N];
void DP (int x)
{
	for (int u=0;u<=n;u++) 
	{
		f[x][u]=f[x-1][u];
	}
	int l=1,r=0;
	for (int u=0;u<=R[x];u++)
	{
		if (u<=n)
		{
			while (l<=r&&f[x-1][u]<=f[x-1][q[r]]) r--;
			q[++r]=u;
		}
		while (l<=r&&u-q[l]>(R[x]-L[x])) l++;	//printf("YES:%d %d %d %d %d\n",u,q[l],l,r,f[x-1][q[l]]);
		if (l<=r) 
		{
			f[x][u]=min(f[x][u],f[x-1][q[l]]+2);
		}
	}
//	printf("YES\n");
	l=1;r=0;
	for (int u=R[x];u>=0;u--)
	{
		if (R[x]-u<=n)
		{	
		//	printf("%d %d %d\n",u);
			while (l<=r&&f[x-1][R[x]-u]<=f[x-1][q[r]]) r--;
			q[++r]=R[x]-u;
		}
	//printf("%d\n",u);
		while (l<=r&&q[l]<L[x]-u) l++;
		if (l<=r) f[x][u]=min(f[x][u],f[x-1][q[l]]+1);
	}
/*	for (int u=1;u<=n;u++) 
	{
		printf("%d %d %d\n",x,u,f[x][u]);
	}*/
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=k;u++)	scanf("%d%d",&L[u],&R[u]);
	memset(f,127,sizeof(f));
	f[0][0]=0;
	for (int u=1;u<=k;u++)		DP(u);
	if (f[k][n]<=2*k) printf("Full\n%d",f[k][n]);
	else printf("Hungry");
	return 0;
}