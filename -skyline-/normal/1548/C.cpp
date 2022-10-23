#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,q;
ll fp(ll x,ll k=orz-2){
	ll a=1;
	while(k){
		if(k&1)(a*=x)%=orz;
		k>>=1,(x*=x)%=orz;
	}
	return a;
}
ll jc[3000005],njc[3000005],f[3000005];
ll c(int x,int y){return jc[x]*njc[y]%orz*njc[x-y]%orz;}
int main(){
	jc[0]=1;
	for(int i=1;i<=3000003;++i)jc[i]=jc[i-1]*i%orz;
	njc[3000003]=fp(jc[3000003]);
	for(int i=3000003;i;--i)njc[i-1]=njc[i]*i%orz;
	scanf("%d%d",&n,&q);
	f[0]=n+1;
	ll _=fp(3);
	f[1]=(n+1ll)*n/2ll*3ll;
	f[1]=(f[1]%orz+orz)%orz;
	for(int i=2;i<=n*3;++i){
		ll x=c(n*3+3,i+1)-3*f[i-1]-f[i-2];
		x=(x%orz*_%orz+orz)%orz;
		f[i]=x;
	}
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%I64d\n",f[x]);
	}
    return 0;
}