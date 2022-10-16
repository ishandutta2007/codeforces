#include<bits/stdc++.h>
using namespace std;
int mx,n,s,a;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a,s+=a,mx=max(mx,a);
	cout<<max(mx,(s*2)/n+1);
	return 0;
}