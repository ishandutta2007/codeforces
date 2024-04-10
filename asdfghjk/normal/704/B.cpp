#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,s,e,i,j,a[5005],b[5005],c[5005],d[5005],x[5005];
long long f[5005][5005];
int main()
{
	scanf("%d%d%d",&n,&s,&e);
	for(i=1;i<=n;++i)
		scanf("%d",x+i);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(i=1;i<=n;++i)
		scanf("%d",b+i);
	for(i=1;i<=n;++i)
		scanf("%d",c+i);
	for(i=1;i<=n;++i)
		scanf("%d",d+i);
	for(i=0;i<=n;++i)
		for(j=0;j<=i;++j)
			f[i][j]=1ll<<60;
	f[0][0]=0;
	for(i=0;i<n;++i)
		for(j=0;j<=i;++j)
		{
			//printf("%d %d %lld\n",i,j,f[i][j]);
			f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+(i+1!=s?-x[i+1]+b[i+1]:0)+(i+1!=e?-x[i+1]+d[i+1]:0));
			if(j&&i+1!=e&&(i+1<s||i+1==s&&(s<e||s==n||j>1)||i+1>s&&j>1))
				f[i+1][j]=min(f[i+1][j],f[i][j]+x[i+1]+c[i+1]+(i+1!=s?-x[i+1]+b[i+1]:0));
			if(j&&i+1!=s&&(i+1<e||i+1==e&&(e<s||e==n||j>1)||i+1>e&&j>1))
				f[i+1][j]=min(f[i+1][j],f[i][j]+x[i+1]+a[i+1]+(i+1!=e?-x[i+1]+d[i+1]:0));
			if(j>1&&i+1!=s&&i+1!=e&&(i+1<max(s,e)||i+1==n||j>2))
				f[i+1][j-1]=min(f[i+1][j-1],f[i][j]+2ll*x[i+1]+c[i+1]+a[i+1]);
		}
	printf("%lld",f[n][1]);
	return 0;
}