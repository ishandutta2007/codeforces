#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 500005;

int n;LL K,a[maxn],sum;
LL down(LL K)
{
	int pos=1;LL o=sum/n;
	while (pos<n) {
		LL t=pos*(a[pos+1]-a[pos]);
		if (K>=t) K-=t,++pos;
		else return min(o,K/pos+a[pos]);
	}
	return o;
}
LL up(LL K)
{
	int pos=n;LL o=(sum-1)/n+1;
	while (pos>1) {
		LL t=(n-pos+1)*(a[pos]-a[pos-1]);
		if (K>=t) K-=t,--pos;
		else return max(o,a[pos]-K/(n-pos+1));
	}
	return o;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("hood.in","r",stdin);
		freopen("hood.out","w",stdout);
	#endif
	scanf("%d %lld",&n,&K);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	printf("%lld",up(K)-down(K));
	return 0;
}