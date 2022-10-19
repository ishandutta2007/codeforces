#include<cstdio>
#include<algorithm>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,t;
LL ans=inf;
LL a[7];
LL b[100002][7];
struct aaa
{
	LL l,r;
}p[100002];
inline bool cmp(aaa a,aaa b)
{
	return a.l==b.l? (a.r<b.r):(a.l<b.l);
}
int main()
{
	for(int i=1;i<=6;++i)scanf("%lld",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&b[i][0]);
		for(int j=1;j<=6;++j)b[i][j]=b[i][0]-a[j];
	}
	for(int i=1;i<=6;++i)
	{
		for(int j=2;j<=n;++j)
		{
			p[j]=(aaa){-inf,inf};
			for(int k=1;k<=6;++k)
			{
				if(b[j][k]<=b[1][i] && b[j][k]>p[j].l)p[j].l=b[j][k];
				if(b[j][k]>=b[1][i] && b[j][k]<p[j].r)p[j].r=b[j][k];
			}
			p[j]=(aaa){b[1][i]-p[j].l,p[j].r-b[1][i]};
		}
		sort(p+2,p+n+1,cmp),t=0;
		for(int j=2;j<=n;++j)
		{
			while(t && p[j].r>=p[t].r)--t;
			p[++t]=p[j];
		}
		p[0].l=p[t+1].r=0;
		for(int j=0;j<=t;++j)ans=min(ans,p[j].l+p[j+1].r);
	}
	printf("%lld",ans);
	return 0;
}