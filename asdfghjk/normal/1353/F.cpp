#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
	long long num;
}g[10005];
int t,n,m,i,j,cnt;
long long a[105][105],f[105][105],ans,w;
bool cmp(node a,node b)
{
	return a.num>b.num;
}
long long work(long long x)
{
	for(int i=0;i<=n+1;++i)
		for(int j=0;j<=m+1;++j)
			f[i][j]=1ll<<61;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(i==1&&j==1)
				f[i][j]=a[1][1];
			else if(x<=a[i][j])
				f[i][j]=min(f[i][j],min(f[i-1][j],f[i][j-1])+a[i][j]);
	return f[n][m];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		cnt=0;
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
			{
				scanf("%lld",a[i]+j);
				a[i][j]-=i-1+j-1;
				g[++cnt]=(node){i,j,a[i][j]};
			}
		sort(g+1,g+1+cnt,cmp);
		ans=1ll<<61;
		for(i=1;i<=cnt;++i)
			if(g[i].num<=a[1][1])
			{
				w=work(g[i].num);
				if(w<(1ll<<61))
					ans=min(ans,w-(n+m-1)*g[i].num);
			}
		printf("%lld\n",ans);
	}
	return 0;
}