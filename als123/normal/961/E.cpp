#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
struct qq
{
	LL x,id;
}s[N];
LL a[N];
bool cmp (qq x,qq y)	{return x.x<y.x;}
LL f[N];
LL lb (LL x){return x&(-x);}
LL find (LL x)
{
	LL lalal=0;
	while (x>0)
	{
		lalal=lalal+f[x];
		x=x-lb(x);
	}
	return lalal;
}
void change (LL x)
{
	while (x<=n)
	{
		f[x]++;
		x+=lb(x);
	}
}
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)
	{
		scanf("%I64d",&a[u]);
		s[u].id=u;s[u].x=a[u];
	}
	sort(s+1,s+1+n,cmp);
//	for (LL u=1;u<=n;u++) printf("%I64d %I64d\n",s[u].x,s[u].id);
	LL now=n;
	LL ans=0;
	for (LL u=n;u>=1;u--)
	{
		while (now>=1&&s[now].x>=u)
		{
			change(s[now].id);
			now--;
		}
		//printf("now:%I64d\n",now);
		//printf("%I64d ",find(u));
		ans=ans+find(min(a[u],u-1));
	}
	printf("%I64d\n",ans);
	return 0;
}