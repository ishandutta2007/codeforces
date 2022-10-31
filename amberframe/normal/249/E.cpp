#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
LL mod = 1e10;
const LL rad = 1e6;

LL mul(LL p,LL k) {
	p%=mod;k%=mod;
	LL p0=p%rad;p/=rad;
	LL k0=k%rad;k/=rad;
	return (p0*k0+p0*k%mod*rad+p*k0%mod*rad+p*k%mod*rad%mod*rad)%mod;
}
LL get2(LL x) {
	LL a=x,b=x+1;
	(a%2?b/=2:a/=2);
	return mul(a,b);
}
LL get3(LL x) {
	LL a=x,b=x+1,c=2*x+1;
	(a%2?(b%2?c/=2:b/=2):a/=2);
	(a%3?(b%3?c/=3:b/=3):a/=3);
	return mul(mul(a,b),c);
}
LL query(LL x,LL y) {
	if (!x||!y) return 0;
	LL _min=min(x,y);
	LL res=get2(_min*_min);
	if (x<y) {
		res+=mul(get3(y-1)-get3(x-1),x);
		res+=mul(get2(x),y-x);
	}
	else {
		res+=mul(get3(x)-get3(y),y);
		res-=mul(get2(y-1),x-y);
	}
	return (res+mod)%mod;
}
LL query(LL x1,LL y1,LL x2,LL y2) {
	return query(x1,y1)+query(x2,y2)-query(x1,y2)-query(x2,y1);
}

int T;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("matrix.in","r",stdin);
		freopen("matrix.out","w",stdout);
	#endif
	for (scanf("%d",&T);T--;) {
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		LL ans1=(query(x1-1,y1-1,x2,y2)%mod+mod)%mod;++mod;
		LL ans2=(query(x1-1,y1-1,x2,y2)%mod+mod)%mod;--mod;
		if (ans1==ans2) printf("%I64d\n",ans1);
		else printf("...%010I64d\n",ans1);
	}
	return 0;
}