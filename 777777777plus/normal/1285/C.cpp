#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;

ll x;
ll ans=1e18;
pair<ll,ll> res;

int main(){
	cin>>x;
	for(ll a=1;a*a<=x;++a)
	if(x%a==0){
		for(ll g=1;g*g<=a;++g)
		if(a%g==0){
			ll b=x/a*g;
			if(__gcd(a,b)==g){
				if(max(a,b)<ans){
					ans=max(a,b);
					res={a,b};
				}
			}
		}
	}
	cout<<res.first<<" "<<res.second<<endl;
}