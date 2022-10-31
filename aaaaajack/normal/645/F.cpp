#include<bits/stdc++.h>
#define M 1001000
#define Q 1000000007
using namespace std;
int cnt[M];
int fac[M],ifac[M];
int phi[M];
int inv(int x){
	int r=1,y=Q-2;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
inline int C(int n,int m){
	if(n<m||m<0) return 0;
	return 1LL*fac[n]*ifac[m]%Q*ifac[n-m]%Q;
}
int main(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<M;i++){
		phi[i]+=i;
		fac[i]=1LL*fac[i-1]*i%Q;
		ifac[i]=inv(fac[i]);
		for(int j=2;i*j<M;j++){
			phi[i*j]-=phi[i];
		}
	}
	long long ans=0;
	int n,k,q;
	scanf("%d%d%d",&n,&k,&q);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j*j<=x;j++){
			if(x%j==0){
				cnt[j]++;
				if(x/j!=j) cnt[x/j]++;
			}
		}
	}
	for(int i=1;i<M;i++){
		ans+=1LL*phi[i]*C(cnt[i],k)%Q;
	}
	ans%=Q;
	while(q--){
		int x;
		scanf("%d",&x);
		for(int j=1;j*j<=x;j++){
			if(x%j==0){
				ans+=1LL*phi[j]*C(cnt[j],k-1)%Q;
				cnt[j]++;
				if(x/j!=j){
					ans+=1LL*phi[x/j]*C(cnt[x/j],k-1)%Q;
					cnt[x/j]++;
				}
			}
		}
		ans%=Q;
		printf("%lld\n",ans);
	}
	return 0;
}