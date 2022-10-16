#include<bits/stdc++.h>
using namespace std;
int n,k,c,l,a,ans;
int main()
{
	cin>>n>>k>>c;
	for(int i=0;i<c;i++)cin>>a,ans+=(a-l-1)/k+1,l=a;
	cout<<ans+(n-l)/k;
	return 0;
}