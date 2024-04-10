#include<bits/stdc++.h>
using namespace std;
int a[999999];
map<int,int>mp;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		bool fl=1;
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]==1)fl=0;
		}
		if(fl){
			cout<<"YES\n";
			continue;
		}
		mp.clear();
		for(i=1;i<=n;++i){
			if(mp[a[i]+1]||mp[a[i]-1]){
				cout<<"NO\n";
				goto gg;
			}
			mp[a[i]]=1;
		}
		cout<<"YES\n";
		gg:;
	}
}