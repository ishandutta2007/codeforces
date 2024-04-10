#include<bits/stdc++.h>
enum{P=998244353};
int f[720729];
int main(){
	int n,a,x,y,k,M,i,j,m=1,s=0,w,o=1;
	for(std::cin>>n>>a>>x>>y>>k>>M,w=k,i=1;i<k;++i)m=m*i/std::__gcd(m,i),w=w*1ll*n%P;
	for(i=k,--n;i;o=o*(n+1ll)%P,--i)for(j=m-1;~j;--j)f[j]=(f[j]*1ll*n+f[j/i*i]+j*1ll*o)%P;
	for(i=0;i<=n;++i)s=(s+f[a%m]+a/m*m*1ll*w)%P,a=(a*1ll*x+y)%M;
	std::cout<<s;
}