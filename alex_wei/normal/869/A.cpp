#include<bits/stdc++.h>
using namespace std;
int n,x[2002],y[2002],t[4000002],cnt; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i],t[x[i]]=1;
	for(int i=1;i<=n;i++)cin>>y[i],t[y[i]]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cnt+=t[x[i]^y[j]];
	cnt%2?cout<<"Koyomi":cout<<"Karen";
	return 0;
}