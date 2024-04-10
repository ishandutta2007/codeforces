#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int n,m,c[1005],r[1005],ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='*')r[i]++,c[j]++,ans++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='*'&&ans-r[i]-c[j]+1==0||mp[i][j]=='.'&&ans-r[i]-c[j]==0)
				cout<<"YES\n"<<i<<" "<<j,exit(0);
	cout<<"NO";
	return 0;
}