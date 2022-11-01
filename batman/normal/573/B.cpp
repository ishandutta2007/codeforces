#include <bits/stdc++.h>
using namespace std;

long long n,h[101*1000],dp1[101*1000],dp2[101*1000],res;
int main()
{
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>h[i];
    dp1[0]=1;
    for(int i=1;i<n;i++)
    {
    	dp1[i]=min(dp1[i-1]+1,h[i]);
	}
    	
	dp2[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		dp2[i]=min(dp2[i+1]+1,h[i]);
	}
		
	for(int i=0;i<n;i++)
	{
		res=max(res,min(dp1[i],dp2[i]));
	}
			
	cout<<res;	
    
    return 0;
}