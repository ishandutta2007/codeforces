#include<bits/stdc++.h>
#define N 3001000
#define Q 1000000007
using namespace std;
int fac[N],ifac[N];
long long ans[N];
int inv(int x){
	int y=Q-2,r=1;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		y>>=1;
		x=1LL*x*x%Q;
	}
	return r;
}
inline int qry(int x){
	return x<0?0:ans[x];
}
long long C(int n,int m){
	if(m<0 || n<m) return 0;
	return 1LL*fac[n]*ifac[m]%Q*ifac[n-m]%Q;
}
int main(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=1LL*i*fac[i-1]%Q;
		ifac[i]=inv(fac[i]);
	}
	long long i3=inv(3);
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n*3;i++){
		ans[i]=(C(n*3+3,i+1)-C(3,i+1)-3LL*qry(i-1)-qry(i-2))%Q;
		if(ans[i]<0) ans[i]+=Q;
		ans[i]=ans[i]*i3%Q;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}