#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const LL N=100005;
LL a[N],b[N];
LL n,m;
map<LL,LL> mp;
LL x;
int main()
{
	scanf("%lld",&n);scanf("%lld",&x); 
	for (LL u=1;u<=n;u++) scanf("%lld",&a[u]);
	scanf("%lld",&m);scanf("%lld",&x);
	for (LL u=1;u<=m;u++) scanf("%lld",&b[u]);
	LL ans=0;
	for (LL k=2;k<=1e10;k<<=1)
	{
		mp.clear();
		for (LL i=1;i<=n;i++)	{int t=a[i]%k;mp[t]++;ans=max(ans,mp[t]);}
		for (LL i=1;i<=m;i++)	{int t=(b[i]%k+k/2)%k;mp[t]++;ans=max(ans,mp[t]);}
	}
	printf("%lld\n",ans);
	return 0;
}