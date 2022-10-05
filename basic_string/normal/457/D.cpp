#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
#define ld long double
ld f[N];
ld c(int n,int m){return f[n]-f[m]-f[n-m];}
int main(){
	int n,m,i,j,k,o;
	ld ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;++i)f[i]=f[i-1]+log((ld)i);
	for(i=0;i<=n;++i)for(j=0;j<=n;++j){
		o=n*(i+j)-i*j;
		if(o<=k)ans+=exp(c(n,i)+c(n,j)+c(m-o,k-o)-c(m,k));
	}
	if(ans<1e99)printf("%.13Lg",ans);else puts("1e99");
	return 0;
}