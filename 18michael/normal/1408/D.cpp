#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,t=0,t1,ans=inf;
struct aaa
{
	int x,y;
}a[2002],b[2002],p[4000002];
inline bool cmp(aaa a,aaa b)
{
	return a.x==b.x? (a.y<b.y):(a.x<b.x);
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		for(int j=1;j<=n;++j)p[++t]=(aaa){max(b[i].x-a[j].x+1,0),max(b[i].y-a[j].y+1,0)};
	}
	sort(p+1,p+t+1,cmp),t1=t,t=0;
	for(int i=1;i<=t1;++i)
	{
		while(t && p[t].y<=p[i].y)--t;
		p[++t]=p[i];
	}
	p[0].x=p[t+1].y=0;
	for(int i=0;i<=t;++i)ans=min(ans,p[i].x+p[i+1].y);
	printf("%d",ans);
	return 0;
}