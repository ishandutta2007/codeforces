#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
const int N=2000010; typedef long long ll; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
const ll mod=1000000007;
ll mul(ll a,ll b,ll m=mod){return a*b%m;}
ll qpow(ll a,ll b,ll m=mod){
	ll ans=1;
	for(;b;a=mul(a,a,m),b>>=1)
		if(b&1)ans=mul(ans,a,m);
	return ans;
}
#define int ll
struct CC{
	static const int N=100010;
	ll fac[N],inv[N];
	CC(){
		fac[0]=1;
		repeat(i,1,N)fac[i]=fac[i-1]*i%mod;
		inv[N-1]=qpow(fac[N-1],mod-2,mod);
		repeat_back(i,1,N)inv[i-1]=inv[i]*i%mod;
	}
	ll operator()(ll a,ll b){ //a>=b
		if(a<b || b<0)return 0;
		return fac[a]*inv[a-b]%mod*inv[b]%mod;
	}
	ll A(ll a,ll b){ //a>=b
		if(a<b || b<0)return 0;
		return fac[a]*inv[a-b]%mod;
	}
}C;
int n,x,pos,a,b;
void BinarySearch(){
	int l=0,r=n; a=b=0;
	while(l<r){
		int m=(l+r)/2;
		if(m==pos)l=m+1;
		else if(m<pos)l=m+1,a++;
		else r=m,b++;
	}
}
void Solve(){
	n=read(),x=read(),pos=read();
	BinarySearch();
	cout<<C.A(x-1,a)*C.A(n-x,b)%mod*C.A(n-a-b-1,n-a-b-1)%mod<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}