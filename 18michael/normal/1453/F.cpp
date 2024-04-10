#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,ans,Test_num;
int a[3002];
int f[3002][3002],g[3002][3002];
inline void upd(int &x,int y)
{
	if(y<x)x=y;
}
inline void solve()
{
	scanf("%d",&n),a[0]=1,ans=inf;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<=n;++i)for(int j=i;j<=i+a[i];++j)f[i][j]=inf;
	for(int i=0;i<=n;++i)
	{
		g[i][i]=0;
		for(int j=i-1;~j;--j)g[j][i]=g[j+1][i]+(j+a[j]>=i);
	}
	for(int i=f[0][1]=0;i<=n;++i)
	{
		for(int j=i+1;j<=i+a[i];++j)upd(f[i][j],f[i][j-1]);
		for(int j=i+1;j<=i+a[i];++j)f[i][j]+=g[i+1][j],upd(f[j][max(i+a[i]+1,j)],f[i][j]);
		if(i+a[i]==n)upd(ans,f[i][n]);
	}
	printf("%d\n",ans);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}