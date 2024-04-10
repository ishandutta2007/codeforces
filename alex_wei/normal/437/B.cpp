#include<bits/stdc++.h>
using namespace std;
int n,m,j,sum,r,ans;
int lowbit(int x){return x&-x;}
int main()
{
	cin>>n>>m,r=n;
	for(int i=1;i<=m;i++)
		sum+=lowbit(i);
	if(sum<n)cout<<-1,exit(0);
	for(int i=m;i>0;i--)
		if(lowbit(i)<=n)
			ans++,n-=lowbit(i);
	cout<<ans<<endl;
	for(int i=m;i>0;i--)
		if(lowbit(i)<=r)
			cout<<i<<" ",r-=lowbit(i);
	return 0;
}