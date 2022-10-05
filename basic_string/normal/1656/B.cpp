#include<bits/stdc++.h>
using namespace std;
int a[999999];
map<int,int>mp;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>k;
		bool fl=0;
		mp.clear();
		for(i=1;i<=n;++i){
			cin>>j;
			if(mp[j+k]||mp[j-k])fl=1;
			mp[j]=1;
		}
		if(fl)cout<<"YES\n";
		else cout<<"NO\n";
	}
}