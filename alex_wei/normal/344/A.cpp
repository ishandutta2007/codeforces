#include<bits/stdc++.h>
using namespace std;
int n,a[100002],ans=1;
int main()
{
	cin>>n>>a[1];
	for(int i=2;i<=n;i++)cin>>a[i],ans+=(a[i]!=a[i-1]);
	cout<<ans;
    return 0;
}