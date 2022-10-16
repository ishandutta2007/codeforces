#include<bits/stdc++.h>
using namespace std;
int m,c[105],s[105],sum,x,y;
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>c[i],sum+=c[i],s[i]=s[i-1]+c[i];
	cin>>x>>y;
	for(int i=1;i<=m;i++)
		if(s[i]<=y&&s[i]>=x&&sum-s[i]>=x&&sum-s[i]<=y)
			cout<<i+1,exit(0);
	cout<<0;
	return 0;
}