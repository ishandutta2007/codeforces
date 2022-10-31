#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=100005,E=262144;
const long long inf=30000000000000000ll;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ans;
}
long long a[205],b[205],c,d,e,f,i,j,x,y,t,ans;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cin>>a[1]>>b[1]>>c>>d>>e>>f;
	cin>>x>>y>>t;
	int n=1;
	for(i=2;a[n]<=inf&&b[n]<=inf;++i)
	{
		a[i]=a[i-1]*c+e;
		b[i]=b[i-1]*d+f;
		++n;
	}
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)
			if(min(abs(a[i]-x)+abs(b[i]-y),abs(a[j]-x)+abs(b[j]-y))+abs(a[j]-a[i])+abs(b[j]-b[i])<=t)
				ans=max(ans,j-i+1);
	cout<<ans;
		
}