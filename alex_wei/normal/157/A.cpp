#include<bits/stdc++.h>
using namespace std;
int n,k,ans,c[33],r[33]; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>k,r[i]+=k,c[j]+=k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans+=(c[j]>r[i]);
	cout<<ans;
	return 0;
}