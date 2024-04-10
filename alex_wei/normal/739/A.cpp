#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,x=1e9;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>l>>r,x=min(x,r-l+1);
	cout<<x<<endl;
	for(int i=1;i<=n;i++)cout<<i%x<<" ";
}