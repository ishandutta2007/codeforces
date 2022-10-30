#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 10005;
const int inf = 1<<30;
int a[maxn],n;LL ans=1;
int solve(int x) {
	if (a[x]==x) return 1;
	for (int b=x,i=1;i<=n;i++) {
		x=a[x];if (x==b) return i&1?i:i/2;
	}
	return inf;
}
LL gcd(LL a,LL b) {return b?gcd(b,a%b):a;}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("plan.in","r",stdin);
		freopen("plan.out","w",stdout);
	#endif
	scanf("%d",&n);ans=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) {
		int t=solve(i);
		if (t>=inf) {puts("-1");return 0;}
		ans=ans/gcd(t,ans)*t;
	}
	printf("%lld",ans);
	return 0;
}