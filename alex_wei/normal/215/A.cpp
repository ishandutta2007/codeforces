#include<bits/stdc++.h>
using namespace std;
int n,m,a[51],b[51],mx,ans; 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[j]%a[i]==0)
				mx=max(mx,b[j]/a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[j]%a[i]==0)
				ans+=mx==b[j]/a[i];
	cout<<ans;
	return 0;
}