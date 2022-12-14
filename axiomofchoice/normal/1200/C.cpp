#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llf long double
ll n,m,q,a,b,c,d,g;
llf x,y;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>q;
	g=gcd(n,m);
	for(int i=0;i<q;i++){
		cin>>a>>b>>c>>d;
		if(a==1)x=((llf)b-0.5)/n;
		else x=((llf)b-0.5)/m;
		if(c==1)y=((llf)d-0.5)/n;
		else y=((llf)d-0.5)/m;
		x*=g;
		y*=g;
		if((ll)x!=(ll)y)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}