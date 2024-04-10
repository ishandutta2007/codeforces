#include<bits/stdc++.h>
using namespace std;
enum{N=300009,P=998244353};
int f[N],g[N],jc[N],ijc[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int C(int n,int m){
	if(n<m||m<0)return 0;
	return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k,w;
	jc[0]=1;
	for(i=1;i<N;++i)jc[i]=jc[i-1]*1ll*i%P;
	ijc[N-1]=qp(jc[N-1],P-2);
	for(i=N-1;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(cin>>T;T--;){
		cin>>n;
		f[0]=f[1]=1;
		for(i=1;i<=n;++i)f[i]=(f[i-1]+(i-1ll)*f[i-2])%P;
		
		g[0]=1;
		for(i=2;i*2<=n;i+=2)g[i]=2*(i-1ll)*g[i-2]%P;
		int ans=0;
		for(i=0;i*2<=n;i+=2)ans=(ans+C(n-i,i)*1ll*g[i]%P*f[n-2*i])%P;
		cout<<ans<<'\n';
	}
}/*
pa=a
pa=b pb=a
pa=b pb=c pc=d pd=a
abs(a-c)<=1 abs(b,d)<=1

fn=fn-1+(n-1)*fn-2
gn=(n-1)*gn-2
fij=fi-4j-1+fi-3j-1+fi-2j-1
C n0
C n-1 1
C n-2 2
*/