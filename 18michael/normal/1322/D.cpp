#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,mx,ans=0;
int l[2002],s[2002],c[4002];
int f[4002][2002];
inline void upd(int &x,int y)
{
	if(y>x)x=y;
}
int main()
{
	scanf("%d%d",&n,&m),mx=n+m;
	for(int i=1;i<=n;++i)scanf("%d",&l[i]);
	for(int i=1;i<=n;++i)scanf("%d",&s[i]);
	for(int i=1;i<=mx;++i)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j)f[i][j]=-inf;
	}
	for(int i=n;i;--i)
	{
		for(int j=n-i+1;j;--j)upd(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
		for(int j=l[i],k=n-i+1;j<mx;++j,k>>=1)for(int o=k;~o;--o)upd(f[j+1][o>>1],f[j][o]+(o>>1)*c[j+1]);
	}
	for(int i=1;i<=mx;++i)ans=max(ans,f[i][0]);
	return 0&printf("%d",ans);
}