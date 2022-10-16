#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll ksm(ll a,ll b){
	ll s=1,m=a%mod;
	while(b){
		if(b&1)s=s*m%mod;
		b>>=1,m=m*m%mod;
	}
	return s;
}
ll n,m,l,r; 
int main(){
	cin>>n>>m>>l>>r;
	if((n&1)&&(m&1))cout<<ksm(r-l+1,n*m);
	else if((r-l+1)&1)cout<<(ksm(r-l+1,n*m)+1)*(mod+1)/2%mod;
	else cout<<ksm(r-l+1,n*m)*(mod+1)/2%mod;
	return 0;
}//