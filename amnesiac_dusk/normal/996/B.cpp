#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#include <bits/stdc++.h>
using namespace std;
int main()
{
	IO
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int gate[n];
	ll mini=1e10;
	int ans=0;
	for(int i=0; i<n; i++)
	{
		gate[i]=i;
		while(gate[i]<a[i])
			gate[i]+=n;
		if(mini>gate[i])
		{
			mini=gate[i];
			ans=i;
		}
	}
	cout<<ans+1;
}