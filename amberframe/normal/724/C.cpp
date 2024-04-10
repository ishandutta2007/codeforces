#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> mp;
#define pb push_back
const LL inf = 1ll<<50;
const int maxn = 200005;

LL ans=inf;int n,m,q;
mp exgcd(LL a,LL b) {
	if (b) {
		mp tmp=exgcd(b,a%b);
		return mp(tmp.second,tmp.first-a/b*tmp.second);
	}
	else return mp(1,0);
}
LL GCD(LL a,LL b) {
	return b?GCD(b,a%b):a;
}
void solve(LL n,LL m,LL x,LL y) {
	LL t=GCD(n,m);
	if ((y-x)%t) return ;
	LL i=exgcd(n,m).first;
	i*=(y-x)/t;LL j=(i*n-y+x)/m;
	LL u=max(-i*t/m,-j*t/n);
	i+=m/t*u;j+=n/t*u;
	while (i<0) i+=m/t,j+=n/t;
	while (j<0) i+=m/t,j+=n/t;
	ans=min(ans,i*n+x);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("tracing.in","r",stdin);
		freopen("tracing.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&q);
	for (int x,y,i=1;i<=q;i++) {
		scanf("%d %d",&x,&y);ans=inf;
		solve(2*n,2*m,x,y);
		solve(2*n,2*m,2*n-x,y);
		solve(2*n,2*m,x,2*m-y);
		solve(2*n,2*m,2*n-x,2*m-y);
		printf("%lld\n",ans!=inf?ans:-1);
	}
	return 0;
}