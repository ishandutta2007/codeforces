#include<bits/stdc++.h>
#define mod 1000000000000000000ll
using namespace std;
int a[100005];
long long fsp(long long x,int y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)ans=ans*x;
		y>>=1;
		x=x*x;
	}
	return ans;
}
long long pdv(long long x,int y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ss=pow(a[n],1.0/(n-1));
	long long ans=LLONG_MAX;
	for(int t=max(1,ss-10);t<=ss+10;t++)
	{
		if((n-1)*log(t)>log(mod))continue;
		long long na=0;
		for(int i=1;i<=n;i++)
		{
			long long ff=fsp(t,i-1);
			if(ff>a[i])na+=ff-a[i];
			else na+=a[i]-ff;
		}
		ans=min(ans,na);
	}
	cout<<ans<<endl;
	return 0;
}