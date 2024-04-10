#include<bits/stdc++.h>
using namespace std;
int n,m,a[1002],c[1002],p=1;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		if(c[i]<=a[p])p++;
	cout<<p-1;
	return 0;
}