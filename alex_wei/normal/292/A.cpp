#include<bits/stdc++.h>
using namespace std;
int n,c[1002],t[1002],ans; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
		c[i]+=max(0,c[i-1]-(t[i]-t[i-1]));
		ans=max(ans,c[i]);
	}
	cout<<t[n]+c[n]<<" "<<ans;
	return 0;
}