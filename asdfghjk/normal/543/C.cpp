#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,k,a[50][50],g[50][50],f[1100000],sum[50][50],mn[50];
char s[50][50];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;++j)
			g[j][s[i][j]-'a']|=1<<(i-1);
	}
	for(i=1;i<=n;++i)
	{
		mn[i]=1<<30;
		for(j=1;j<=m;++j)
		{
			scanf("%d",a[i]+j);
			sum[j][s[i][j]-'a']+=a[i][j];
			mn[i]=min(mn[i],a[i][j]);
		}
	}
	for(i=1;i<(1<<n);++i)
	{
		f[i]=1<<30;
		for(j=1;j<=n;++j)
			if(i>>(j-1)&1)
			{
				f[i]=min(f[i],f[i^(1<<(j-1))]+mn[j]);
				for(k=1;k<=m;++k)
					f[i]=min(f[i],f[i^(i&g[k][s[j][k]-'a'])]+sum[k][s[j][k]-'a']-a[j][k]);
			}
	}
	printf("%d",f[(1<<n)-1]);
	return 0;
}