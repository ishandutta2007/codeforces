
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll an=1e18,n;cin>>n;
	vector<ll> ls(n);
	for(ll &x:ls) cin>>x;
	sort(ls.begin(),ls.end());n--;
	for(int u=1;u<=31623;u++){
		ll cn=0,s=0;
	if(pow(u,n)>1e10) break;
		for(ll x:ls){
			cn+=abs(x-pow(u,s));s++;}
		an=min(an,cn);
	}
cout<<an;
}