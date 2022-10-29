#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a,b,i,j,g,x,y,z,w[3005][3005],q[3005][3005],bg[3005],ed[3005],p[3005],que[3005],st,fn;
long long ans;
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	scanf("%d%d%d%d",&g,&x,&y,&z);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			w[i][j]=g;
			g=(1ll*g*x+y)%z;
		}
	for(i=1;i<=m;++i)
	{
		q[i][bg[i]=ed[i]=1]=1;
		for(j=2;j<a;++j)
		{
			while(bg[i]<=ed[i]&&w[j][i]<=w[q[i][ed[i]]][i])
				--ed[i];
			q[i][++ed[i]]=j;
		}
	}
	for(i=a;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			while(bg[j]<=ed[j]&&w[i][j]<=w[q[j][ed[j]]][j])
				--ed[j];
			q[j][++ed[j]]=i;
		}
		for(j=1;j<=m;++j)
		{
			p[j]=w[q[j][bg[j]]][j];
			//printf("%d ",p[j]);
		}
		//puts("");
		que[st=fn=1]=1;
		for(j=2;j<b;++j)
		{
			while(st<=fn&&p[j]<=p[que[fn]])
				--fn;
			que[++fn]=j;
		}
		for(j=b;j<=m;++j)
		{
			while(st<=fn&&p[j]<=p[que[fn]])
				--fn;
			que[++fn]=j;
			ans+=p[que[st]];
			while(st<=fn&&que[st]<j+1-b+1)
				++st;
		}
		for(j=1;j<=m;++j)
			while(bg[j]<=ed[j]&&q[j][bg[j]]<i+1-a+1)
				++bg[j];
	}
	printf("%lld",ans);
	return 0;
}