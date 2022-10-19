#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n,t=0;LL ans=0;
LL num[200002]={},val[200002]={};
struct aaa
{
	LL x,y,v;
}p[200002];
inline bool cmp(aaa a,aaa b)
{
	return a.x<b.x? 1:0;
}
inline bool cmp1(aaa a,aaa b)
{
	return a.v==b.v? (a.x<b.x):(a.v<b.v);
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x,LL d,LL arr[])
{
	while(x<=n)arr[x]+=d,x+=lowbit(x);
}
inline LL query(int x,LL arr[])
{
	LL res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&p[i].x);
	for(int i=1;i<=n;++i)scanf("%lld",&p[i].v);
	sort(p+1,p+n+1,cmp);
	for(int i=1,j,la;i<=n;i=j)
	{
		++t,la=p[i].x;
		for(j=i;p[j].x==la;++j)p[j].y=t;
	}
	sort(p+1,p+n+1,cmp1);
	for(int i=1;i<=n;++i)ans+=p[i].x*query(p[i].y-1,num)-query(p[i].y-1,val),modify(p[i].y,p[i].x,val),modify(p[i].y,1,num);
	printf("%lld",ans);
	return 0;
}