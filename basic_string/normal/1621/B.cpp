#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>mp;
map<int,int>mp2,mp3;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,mn,mx,ans;
	for(cin>>T;T--;){
		cin>>n;mp={},mp2=mp3={};mn=2e9,mx=-2e9;
		while(n--){
			cin>>i>>j>>k;mn=min(mn,i);;mx=max(mx,j);
			if(!mp.count({i,j})||mp[{i,j}]>k)mp[{i,j}]=k;
			if(!mp2.count(i)||mp2[i]>k)mp2[i]=k;
			if(!mp3.count(j)||mp3[j]>k)mp3[j]=k;
			ans=2e9+9;
			if(mp.count({mn,mx}))ans=mp[{mn,mx}];
			ans=min(ans,mp2[mn]+mp3[mx]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}