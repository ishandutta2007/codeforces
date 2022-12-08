#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

ll n,k;

ll cnt(ll x){
	ll ret=0,w=1,y=0,c=0;
	if(x%2==0)y=x+1;
	while(x<=n){
		if(((n>>c)<<c)==x)ret+=(n&((1ll<<c)-1))+1;
		else{
			ret+=w;
		}
		if(y&&y<=n){
			if(((n>>c)<<c)==y)ret+=(n&((1ll<<c)-1))+1;
			else{
				ret+=w;
			}
		}
		x<<=1;y<<=1;
		w<<=1;c++;
	}
	return ret;
}

int main(){
	cin>>n>>k;
	ll ans=0;
	for(int t=1;t<=60;++t){
		ll val=1ll<<t-1;
		if(cnt(val)<k)break;
		for(int i=1;i<t;++i){
			ll w=1ll<<t-1-i;
			if(cnt(val|w)>=k)val|=w;
		}
		ans=val;
	}
	cout<<ans<<endl;
}
/*
1000000000000000000 1
*/