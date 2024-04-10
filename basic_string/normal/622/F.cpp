#include<cstdio>
const long long P=1e9+7;
const int N=1e6+7;
long long fc[N],pr[N],ne[N];
long long qp(long long x,long long y){
	register long long r=1;
	while(y){
		if(y&1)r=r*x%P;
		x=x*x%P,y>>=1;
	} 
	return r;
}
int main(){
	register int n,k,i;
	register long long u=0,w=0;
	scanf("%d%d",&n,&k),k+=2;
	fc[0]=pr[0]=ne[k+1]=1;
	for(i=1;i<=k;++i)pr[i]=pr[i-1]*(n-i)%P,fc[i]=fc[i-1]*i%P;
	for(i=k;i;--i)ne[i]=ne[i+1]*(n-i)%P;
	for(i=1;i<=k;++i){
		u=(u+qp(i,k-2))%P;
		w=(w+u*pr[i-1]%P*ne[i+1]%P*qp(fc[i-1]*fc[k-i]*((k-i)&1?-1:1)%P,P-2))%P;
	}
	printf("%lld",(w+P)%P);
	return 0;
}