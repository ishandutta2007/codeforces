#include<bits/stdc++.h>
#define N 200100
#define Q 998244353
using namespace std;
int a[N];
int fac[N],ifac[N];
int qp(int a,int y){
	int r=1;
	while(y){
		if(y&1) r=1LL*r*a%Q;
		y>>=1;
		a=1LL*a*a%Q;
	}
	return r;
}
int inv(int a){
	return qp(a,Q-2);
}
int main(){
	int n,k,a1,a2=0,sm=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i&&a[i]==a[i-1]) sm++;
	}
	if(a[n-1]==a[0]) sm++;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=1LL*fac[i-1]*i%Q;
		ifac[i]=inv(fac[i]);
	}
	if(k==1){
		puts("0");
	}
	else{
		a1=qp(k,n-sm);
		if(a1%2) a1+=Q;
		a1/=2;
		for(int i=0;i<=n-sm;i+=2){
			long long cni=1LL*fac[n-sm]*ifac[i]%Q*ifac[n-sm-i]%Q;
			int xk=qp(k-2,n-sm-i);
			int cii2=1LL*fac[i]*ifac[i/2]%Q*ifac[i/2]%Q;
			a2=(a2+cni*xk%Q*cii2%Q)%Q;
		}
		if(a2%2) a2+=Q;
		a2/=2;
		printf("%d\n",1LL*(a1+Q-a2)*qp(k,sm)%Q);
	}
	return 0;
}