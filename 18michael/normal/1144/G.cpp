#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[200002];
int f[200002][2],from[200002][2];
inline void upd(int x,int y,int z,int w)
{
	if((!y && z>f[x][y]) || (y && z<f[x][y]))f[x][y]=z,from[x][y]=w;
}
inline void print(int x,int y)
{
	if(!x)return ;
	print(x-1,from[x][y]),printf("%d ",y);
}
int main()
{
	scanf("%d",&n),f[1][0]=inf,f[1][1]=-inf;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
	{
		f[i+1][0]=-inf,f[i+1][1]=inf;
		if(f[i][0]>a[i+1])upd(i+1,1,a[i],0);
		if(a[i]<a[i+1])upd(i+1,0,f[i][0],0);
		if(f[i][1]<a[i+1])upd(i+1,0,a[i],1);
		if(a[i]>a[i+1])upd(i+1,1,f[i][1],1);
	}
	if(f[n][0]>-inf)puts("YES"),print(n,0);
	else if(f[n][1]<inf)puts("YES"),print(n,1);
	else puts("NO");
	return 0;
}