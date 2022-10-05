/*
Tima the best
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO(nm) freopen(nm".in","r",stdin); freopen(nm".out","w",stdout);                  
#define ll long long                                                                                                           
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=4e5+123,N=500,mod=1e9+9; 
ll n,a,b,k,x;
string s;
ll binpow(ll n,ll p){
	if(p==0)
		return 1;
	ll c=binpow(n,p/2);
	if(p%2==0)
		return c*c%mod;
	return c*c%mod*n%mod;
}
int main(){ 
	cin>>n>>a>>b>>k;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='+')
			x+=binpow(a,n-i)*binpow(b,i)%mod;
		else
			x-=binpow(a,n-i)*binpow(b,i)%mod;
		if(x<0)
			x+=mod;
	   	if(x>=mod)
	   		x-=mod;
	}
	ll q=b*binpow(a,mod-2)%mod;
	q=binpow(q,k);
	if(q==1){
		cout<<x*( (n+1)/k )%mod;
		return 0;
	}
	q=(binpow(q,(n+1)/k)-1)*binpow(q-1,mod-2)%mod;
	ll ans=q*x%mod;
	cout<<(ans+mod)%mod;
}