#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int s=0,i,n,t=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)t=t*1ll*i%P;
	s=t*1ll*n%P;
	for(i=2;i<=n;++i)s=(s-t)%P,t=t*1ll*qp(i,P-2)%P;
	printf("%d",(s+P)%P);
	return 0;
}