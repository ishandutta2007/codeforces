#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[150005],ans=1; 
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1];
	for(int i=2;i+k-1<=n;i++)
		if(a[i+k-1]-a[i-1]<a[ans+k-1]-a[ans-1])
			ans=i;
	cout<<ans<<endl; 
	return 0;
}