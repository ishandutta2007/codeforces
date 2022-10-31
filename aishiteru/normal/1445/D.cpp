#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,i,t,x,a[2000005],b[100005];
long long p,s,su=1,s2=1;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=2*n;++i)
	{
		scanf("%d",&a[i]);
		s2=s2*i%M;
	}
	sort(a+1,a+1+2*n);
	for(i=1;i<=n;++i)
	{
		s-=a[i];
		su=su*i%M;
	}
	for(i=n+1;i<=2*n;++i)
		s+=a[i];
	su=qpow(su,M-2);
	cout<<(s%M*su%M*su%M*s2%M+M)%M;
}