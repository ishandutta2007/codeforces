#include <bits/stdc++.h>
using namespace std;
#define N (22000)
int n,a[N],maxi=-(1e9);

void solve(int x)
{
	if(x<3)
		return;
	for(int i=0;i<n/x;i++)
	{
		int ans=0;
		for(int j=i;j<n;j+=n/x)
			ans+=a[j];
		maxi=max(ans,maxi);		
	}	
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(long long i=1;i*i<=n;i++)
		if(n%i==0)
		{
			solve(n/i);
			solve(i);
		}
	cout<<maxi;	
    return 0;
}