#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll h,w,ans=1,pd,r[1005],c[1005],mp[1005][1005];
int main()
{
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		cin>>r[i];
		for(int j=1;j<=r[i];j++)
			mp[i][j]=1;
		mp[i][r[i]+1]=2;
	}
	for(int i=1;i<=w;i++){
		cin>>c[i];
		for(int j=1;j<=c[i];j++)
			if(mp[j][i]!=2)
				mp[j][i]=1;
			else cout<<0,exit(0);
		if(mp[c[i]+1][i]!=1)
			mp[c[i]+1][i]=2;
		else cout<<0,exit(0);
	}
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(!mp[i][j])
				ans=(ans*2)%mod,pd=1;
	cout<<ans;
    return 0;
}