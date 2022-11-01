#include <bits/stdc++.h>
using namespace std;
#define ll int

ll m,n,ans,ans2=-1;

int main()
{
	cin>>m>>n;
	if(n==1)return cout<<-1,0;
	if(m==n)return cout<<5,0;
	if(m-n+1<=n)ans2=11;
	if(m>n)m-=n-2,ans+=4;
	while(1)
	{
		if(m*2<=n)return cout<<ans+1,0;
		if(m<n)return cout<<ans+3,0;
		if(m==n)return cout<<ans+5,0;
		if(n<=3)return cout<<ans2,0;
		m-=n/2-1,ans+=2;
	}
	return 0;
}