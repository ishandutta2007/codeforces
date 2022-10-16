#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,f[10005],t[10005],ans=-1e9;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>f[i]>>t[i],ans=max(ans,t[i]<=k?f[i]:f[i]-(t[i]-k));
	cout<<ans;
	return 0;
}