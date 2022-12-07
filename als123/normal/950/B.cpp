#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long LL;
const LL N=100005;
LL n,m;
LL a[N],b[N];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (LL u=1;u<=n;u++) scanf("%I64d",&a[u]);
	for (LL u=1;u<=m;u++) scanf("%I64d",&b[u]);
	LL ans=0;
	LL now=1,now1=1;
	LL x=a[1],y=b[1];
	while (now<=n||now1<=m)
	{	
	//	printf("%I64d %I64d %I64d %I64d\n",x,y,now,now1);
		if (x==y)	
		{
		
			ans++;x=a[++now];y=b[++now1];
		}
		else if (x<y)	x=x+a[++now];
		else	y=y+b[++now1];
	}
	printf("%I64d\n",ans);
	return 0;
}