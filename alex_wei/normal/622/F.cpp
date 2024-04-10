#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod=1e9+7;
const int N=1e6+5;

ll ksm(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%mod;
		a=a*a%mod,b>>=1;
	} return s;
} ll inv(ll x){return ksm(x,mod-2);}

ll n,k,ans;
ll p[N],s[N],fc[N];
int main(){
	cin>>n>>k,s[k+2]=1;
	for(int i=0;i<=k+1;i++)fc[i]=i?fc[i-1]*i%mod:1,p[i]=i?p[i-1]*(n-i)%mod:n;
	for(int i=k+1;~i;i--)s[i]=i==k+1?n-i:s[i+1]*(n-i)%mod;
	for(ll i=1,res=0;i<=k+1;i++){
		res=(res+ksm(i,k))%mod;
		ans=(ans+p[i-1]*s[i+1]%mod*res%mod*ksm(fc[i]*((k-i)&1?1:-1)*fc[k+1-i]%mod,mod-2))%mod;
	} cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}