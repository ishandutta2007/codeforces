#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const ll mod = 998244353;

int n,a[N];

ll qpow(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1)r=r*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return r;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=2*n;++i)scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	ll c=1;
	for(int i=n;i<2*n;++i)c=c*i%mod;
	for(int i=1;i<=n;++i)c=c*qpow(i,mod-2)%mod;
	ll tot=0;
	for(int i=1;i<=n;++i)tot=(tot-a[i]+mod)%mod;
	for(int i=n+1;i<=2*n;++i)tot=(tot+a[i])%mod;
	ll ans=tot*c%mod;
	cout<<ans*2%mod<<endl;
}