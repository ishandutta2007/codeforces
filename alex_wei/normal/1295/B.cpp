#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll t,n,x,dif[N];
string s;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>x>>s;
		ll o=0,z=0;
		for(ll i=0;i<s.size();i++){
			if(s[i]=='0')z++;
			else o++;
			dif[i+1]=z-o;
		}
		if(dif[n]==0){
			ll in=0;
			for(ll i=1;i<=n;i++)in|=dif[i]==x;
			if(in)puts("-1");
			else puts("0");
			continue;
		}
		else{
			ll ans=x==0;
			for(ll i=1;i<=n;i++)ans+=(x-dif[i])*dif[n]>=0&&(x-dif[i])%dif[n]==0;
			cout<<ans<<endl;
		}
	}
	return 0;
}