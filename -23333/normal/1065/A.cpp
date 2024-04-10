#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	//freopen("p.in","r",stdin);
	//freopen("p.out","w",stdout);
	
	ll t,a,b,c,v;
	cin>>t;
	for(int x=1;x<=t;x++){
		cin>>v>>a>>b>>c;
		ll ans=0;
		ll az=v/(a*c);
		ans+=az*(a+b)+(v-az*a*c)/c;
		cout<<ans<<endl;
	}
	return 0;
}