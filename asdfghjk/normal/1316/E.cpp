#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int id,num;
}a[100005];
int n,p,K,i,j,k,w[150][10],cnt[150],s[100005][10];
long long f[100005][150];
bool cmp(node a,node b)
{
	return a.num>b.num;
}
int main()
{
	scanf("%d%d%d",&n,&p,&K);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=p;++j)
			scanf("%d",s[i]+j);
	sort(a+1,a+1+n,cmp);
	for(i=0;i<(1<<p);++i)
		for(j=1;j<=p;++j)
			if(i>>(j-1)&1)
				w[i][++cnt[i]]=j;
	for(i=0;i<=n;++i)
		for(j=0;j<(1<<p);++j)
			f[i][j]=-1;
	f[0][0]=0;
	for(i=0;i<n;++i)
		for(j=0;j<(1<<p);++j)
			if(f[i][j]>-1)
			{
				for(k=1;k<=cnt[((1<<p)-1)^j];++k)
					f[i+1][j|(1<<(w[((1<<p)-1)^j][k]-1))]=max(f[i+1][j|(1<<(w[((1<<p)-1)^j][k]-1))],f[i][j]+s[a[i+1].id][w[((1<<p)-1)^j][k]]);
				if(i+1-cnt[j]<=K)
					f[i+1][j]=max(f[i+1][j],f[i][j]+a[i+1].num);
				else
					f[i+1][j]=max(f[i+1][j],f[i][j]);
			}
	printf("%lld",f[n][(1<<p)-1]);
	return 0;
}