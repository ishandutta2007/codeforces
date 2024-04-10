#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 200005;

LL x[maxn],T,s;int n,ans[maxn],a[maxn];
struct node {
	LL o,x;int i;
}p[maxn];
bool comp(node a,node b) {
	if (a.o!=b.o) return a.o<b.o;
	if (a.x!=b.x) return a.x<b.x;
	return a.i>b.i;
}
LL fpm(LL p,LL k,LL mod) {
	LL res=1ll;p%=mod;
	while (k) {
		if (k&1) (res*=p)%=mod;
		(p*=p)%=mod;k>>=1;
	}
	return res;
}
LL phi(LL n) {
	LL res=n;
	for (LL i=2;i*i<=n;i++)
	if (n%i==0) {
		res=res/i*(i-1);
		while (n%i==0) n/=i;
	}
	if (n>1) res=res/n*(n-1);
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("astronomers.in","r",stdin);
		//freopen("astronomers.out","w",stdout);
	#endif
	scanf("%lld %d",&T,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++) x[i]=x[i-1]+a[i];
	s=x[n]+a[1];LL d=__gcd(s,T),_=fpm(s/d,phi(T/d)-1,T/d);
	for (int i=1;i<=n;i++)
		p[i]=(node){x[i]%d,x[i]/d%(T/d)*_%(T/d),i};
	sort(p+1,p+n+1,comp);
	for (int j,i=1;i<=n;i=j)
	{
		j=i;while (j<=n&&p[j].o==p[i].o) ++j;
		for (int k=i;k<j-1;k++)
			ans[p[k].i]=p[k+1].x-p[k].x;
		ans[p[j-1].i]=T/d+p[i].x-p[j-1].x;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}