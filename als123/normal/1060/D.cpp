#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;
const LL N=100005;
LL n;
LL l[N],r[N];
int main()
{
	scanf("%lld",&n);
	LL ans=n;
	for (LL u=1;u<=n;u++)		
	{
		scanf("%lld%lld",&l[u],&r[u]);
		ans=ans+l[u]+r[u];
	}
	sort(l+1,l+1+n);
	sort(r+1,r+1+n);
	for (LL u=1;u<=n;u++)	ans=ans-min(l[u],r[u]);
	printf("%lld\n",ans);
	return 0;
}