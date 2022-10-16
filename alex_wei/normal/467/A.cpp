#include<bits/stdc++.h>
using namespace std;
int n,p,q,ans; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p>>q,ans+=p+2<=q;
	cout<<ans;
	return 0;
}