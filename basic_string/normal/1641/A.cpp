#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
using ll=long long;
ll a[N];
map<ll,int>mp;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	ll x;
	for(cin>>T;T--;){
		cin>>n>>x;
		for(i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+n+1);mp={};
		for(i=1;i<=n;++i){
			if(mp[a[i]]){
				--mp[a[i]];
			}else ++mp[a[i]*x];
		}
		int ans=0;
		for(auto o:mp)ans+=o.second;
		cout<<ans<<'\n';
	}
	return 0;
}