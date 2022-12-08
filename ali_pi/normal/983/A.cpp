#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>  

using namespace :: std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin>>n;
	while(n--){
		ll p,q,b;
		cin>>p>>q>>b;
		ll gc=__gcd(q,p);
		q/=gc;
		p/=gc;

		gc=__gcd(b,q);
		q/=gc;
		for(ll i=0;i<64 && q!=1;i++){
			if(q%gc!=0){
				gc=__gcd(gc,q);
			}
			if(gc==1){
				break;
			}
			q/=gc;
		}
		if(q==1){
			cout<<"Finite\n";
		}else{
			cout<<"Infinite\n";
		}
	}
}