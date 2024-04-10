#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
#include<algorithm>
typedef unsigned long long ll;
typedef long long ld;
ld a[1111111],b[1111111],c[1111111];
int sa,sb,sc;
ll del(ll x,ll y,ll z)
{return(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);}
ll ans;
void solve(ld*x,ld*y,ld*z,int sx,int sy,int sz)
{
	for(register int i=1;i<sx;i++)
	{
		ll X=x[i],Y=y[std::upper_bound(y+1,y+sy+1,x[i])-y-1],
		Z=z[std::lower_bound(z+1,z+sz+1,Y)-z];
		ll ret=del(X,Y,Z);
		if(ret<ans)ans=ret;
	}
}
void exec()
{
	ans=1e19;
	scanf("%d%d%d",&sa,&sb,&sc);
	register int i;
	a[0]=b[0]=c[0]=-1e9;
	for(i=1;i<=sa;i++)scanf("%d",a+i);
	a[++sa]=2e9;
	for(i=1;i<=sb;i++)scanf("%d",b+i);
	b[++sb]=2e9;
	for(i=1;i<=sc;i++)scanf("%d",c+i);
	c[++sc]=2e9;
	std::sort(a+1,a+sa+1);
	std::sort(b+1,b+sb+1);
	std::sort(c+1,c+sc+1);
	solve(a,b,c,sa,sb,sc);
	solve(b,a,c,sb,sa,sc);
	solve(c,b,a,sc,sb,sa);
	solve(a,c,b,sa,sc,sb);
	solve(b,c,a,sb,sc,sa);
	solve(c,a,b,sc,sa,sb);
	printf("%llu\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/