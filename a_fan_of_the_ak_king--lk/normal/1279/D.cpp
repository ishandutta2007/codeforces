#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=1000005,M=998244353;
int n,i,t,a,k,f[N],j,e[N];
long long ans,s;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		b>>=1;
		s=s*s%M;
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		ans+=k;
		for(j=1;j<=k;++j)
		{
			scanf("%d",&a);
			++f[a];
			e[a]=(e[a]+qpow(1ll*k*n%M,M-2))%M;
		}
	}
	for(i=1;i<=1000000;++i)
		s=(s+1ll*e[i]*f[i])%M;
	cout<<(s*qpow(n,M-2))%M;
}