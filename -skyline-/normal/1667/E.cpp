#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
using namespace std;
int n,k;
ll jc[200005],njc[200005],inv[200005],a[200005],ans[200005];
ll fp(ll x,int k=orz-2){
	ll a=1;
	while(k){
		if(k&1)(a*=x)%=orz;
		k>>=1,(x*=x)%=orz;
	}
	return a;
}
int main(){
	scanf("%d",&n);
	k=(n+1)>>1;
	jc[0]=1;
	for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%orz;
	njc[n]=fp(jc[n]);
	for(int i=n;i;--i)njc[i-1]=njc[i]*i%orz;
	for(int i=1;i<=n;++i)inv[i]=njc[i]*jc[i-1]%orz;
	for(int i=1;i<=k;++i)a[i]=jc[n-i]*jc[k-1]%orz*njc[k-i]%orz;
	ll s=0;
	for(int i=k;i;--i){
		ans[i]=(a[i]-s*inv[i]%orz+orz)%orz;
		(s+=ans[i])%=orz;
	}
	for(int i=1;i<n;++i)printf("%I64d ",ans[i]);
	printf("%I64d\n",ans[n]);
    return 0;
}