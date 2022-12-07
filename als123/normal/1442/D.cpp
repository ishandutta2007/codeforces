#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=1000005;
vector<LL> vec[N];
LL n,k;
LL len[N];
LL ans=0;
LL f[23][N];
void solve (LL l,LL r,LL w)
{
	if (l==r)
	{
		for (LL u=0;u<=min(k,len[l]);u++) ans=max(ans,f[w][k-u]+vec[l][u]);
		return ;
	}
	LL mid=(l+r)>>1;
	
	for (LL u=0;u<=k;u++) f[w+1][u]=f[w][u];
	for (LL u=l;u<=mid;u++) 
	for (LL i=k;i>=len[u];i--)
	f[w+1][i]=max(f[w+1][i],f[w+1][i-len[u]]+vec[u][len[u]]);
	solve(mid+1,r,w+1);
	
	for (LL u=0;u<=k;u++) f[w+1][u]=f[w][u];
	for (LL u=mid+1;u<=r;u++) 
	for (LL i=k;i>=len[u];i--)
	f[w+1][i]=max(f[w+1][i],f[w+1][i-len[u]]+vec[u][len[u]]);
	solve(l,mid,w+1);
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for (LL u=1;u<=n;u++)
	{
		scanf("%lld",&len[u]);
		LL sum=0;vec[u].push_back(0);
		for (LL i=1;i<=len[u];i++)
		{
			LL x;
			scanf("%lld",&x);
			sum=sum+x;
			vec[u].push_back(sum);
		}
	}
	solve(1,n,0);
	printf("%lld\n",ans);
	return 0;
}