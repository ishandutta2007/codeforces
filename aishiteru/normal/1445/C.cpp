#include<bits/stdc++.h>
using namespace std;
int n,i,t;
long long p,q;
long long Test(long long i)
{
	if(i==1)
		return 1;
	long long t=p;
	while(t%q==0)
		t/=i;
	return t;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>p>>q;
		if(p%q==0)
		{
			long long ans=1;
			for(i=1;i*i<=q;++i)
				if(q%i==0)
				{
					ans=max(ans,Test(i));
					ans=max(ans,Test(q/i));
				}
			cout<<ans<<endl;
		}
		else
			cout<<p<<endl;
	}
}