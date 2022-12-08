#include<bits/stdc++.h>
using namespace std;
long long ans=1e18;
long long n,L,c[40];
int main()
{
	cin>>n>>L;
	for (int i=0;i<30;i++) 
	   c[i]=1e18;
	for (int i=0;i<n;i++)
	   cin>>c[i];
	for (int i=1;i<30;i++) 
	   c[i]=min(c[i],c[i-1]*2);
	for (int i=0;i<30;i++){
		long long cost=0;
		for (int j=i;j<30;j++)
		if (L>>j&1)
		   cost+=c[j];
		if (L&((1<<i)-1)) 
		   cost+=c[i];
		ans=min(ans,cost);
	}
	cout<<ans<<endl;
	return 0;
}