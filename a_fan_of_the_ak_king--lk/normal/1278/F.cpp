#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int n,m,k,i;
long long s[5005],ans;
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
	scanf("%d %d %d",&n,&m,&k);
	s[0]=1;
	for(i=1;i<=k;++i)
	{
		for(ri j=i;j>=1;--j)
			s[j]=(s[j-1]+s[j]*j)%M;
		s[0]=0;
	}
	long long tot=1,a=qpow(m,M-2),b=(m-1)*qpow(m,M-2)%M;
	for(i=1;i<=k;++i)
	{
		tot=tot*(n-i+1)%M;
		if(i<=n)
			ans=(ans+s[i]*tot%M*qpow(a,i)%M*qpow(a+b,n-i))%M;
	}
	cout<<(ans%M+M)%M;
}