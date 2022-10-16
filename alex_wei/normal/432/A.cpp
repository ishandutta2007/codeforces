#include<bits/stdc++.h>
using namespace std;
int n,k,c[2002],ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>c[i],ans+=(5-c[i]>=k);
	cout<<ans/3;
	return 0;
}