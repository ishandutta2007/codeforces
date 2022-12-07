#include<bits/stdc++.h>
using namespace std;
int t,T,n,x[5010],a[5010],u[5010],f[5010][5010],g[5010][5010];
inline int dp(int l,int r)
{
	if(r-l<=0 || r-l==1 && x[l]==x[r])
		return 0;
	if(g[l][r]==t)
		return f[l][r];
	int i;
	f[l][r]=1e9;
	for(i=a[l];i<r;i=a[i])
		f[l][r]=min(f[l][r],dp(l,i)+dp(i,r));
	f[l][r]=min(f[l][r],dp(l+1,(i==r)?(r-1):r)+1);
	g[l][r]=t;
	return f[l][r];
}
int main()
{
	int i;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&x[i]);
		for(i=1;i<=n;i++)
			u[i]=n+1;
		for(i=n;i>0;i--)
		{
			a[i]=u[x[i]];
			u[x[i]]=i;
		}
		printf("%d\n",dp(1,n));
	}
	return 0;
}