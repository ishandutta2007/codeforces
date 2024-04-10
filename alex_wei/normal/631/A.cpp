#include<bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005],k[1005][1005],g[1005][1005],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++)
			g[j][i]=g[j][i-1]|a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=i;j++)
			k[j][i]=k[j][i-1]|b[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,k[i][j]+g[i][j]);
	cout<<ans;
	return 0;
}