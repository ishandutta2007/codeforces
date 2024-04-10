#include<bits/stdc++.h>
using namespace std;
int n,a,s,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a,s-=a,ans=max(ans,s);
	cout<<ans;
    return 0;
}