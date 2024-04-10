#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,k,i,j,u,v;
	cin>>n>>k,n=k+1;
	for(i=1;i<=n;++i){
		cout<<"? ";
		for(j=1;j<=n;++j)if(i^j)cout<<j<<' ';
		cout<<endl,cin>>u>>v,++mp[v];
	}
	cout<<"! "<<mp.rbegin()->second;
	return 0;
}