#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ll t,a,b;
	cin>>t>>a>>b;
	if(a==t){
		if(a==b){
			if(a==1)cout<<"inf";
			else cout<<2;
		}else cout<<0;
	}else if(a==b)cout<<1;
	else if(a>t&&b>a){
		ll u=1,v=0;
		while(b)v+=b%a*u,b/=a,u*=t;
		if(v==a||(v==1&&t==1))cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
}