#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T;
ll n,b,g;

int main(){
	cin>>T;
	while(T--){
		cin>>n>>g>>b;
		ll l=n,r=2e18;
		while(l!=r){
			ll mid=l+r>>1;
			ll w=mid/(g+b);
			ll res=mid%(g+b);
			if(w*g+min(res,g)>=(n+1)/2)r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
}