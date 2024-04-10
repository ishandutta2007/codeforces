#include<bits/stdc++.h>
using namespace std; 
const int N=500005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,i,t,j;
long long a[N],p[N],q[N],ans;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
			p[i]=q[i]=0;
		}
		ans=0;
		for(i=0;i<60;++i)
		{
			int s=0;
			for(j=1;j<=n;++j)
				if(a[j]>>i&1)
					++s;
			for(j=1;j<=n;++j)
				if(a[j]>>i&1)
				{
					p[j]=(p[j]+(1ll<<i)%M*s)%M;
					q[j]=(q[j]+(1ll<<i)%M*n)%M;
				}
				else
					q[j]=(q[j]+(1ll<<i)%M*s)%M;
		}
		long long ans=0;
		for(i=1;i<=n;++i)
			ans=(ans+p[i]*q[i])%M;
		printf("%lld\n",(ans%M+M)%M);
	}
}