#include<bits/stdc++.h>
using namespace std;
int n,h[100005],ans; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i],ans=max(ans,h[i]);
	cout<<ans;
	return 0;
}