#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,P=1e9+7;
int jc[N],ijc[N],g[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int C(int n,int m){
	return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,n,m,k,ans;
	for(jc[0]=1,i=1;i<N;++i)jc[i]=jc[i-1]*1ll*i%P,g[i]=i*1ll*qp(2,i-1)%P;
	ijc[N-1]=qp(jc[N-1],P-2);
	for(i=N-1;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(cin>>T;T--;){
		cin>>n>>m>>k;
		if(n==m){
			cout<<g[n]*1ll*qp(qp(2,n-1),P-2)%P*k%P<<'\n';
			continue;
		}
		ans=0;
		for(i=0;i<m;++i)ans=(ans+g[m-i]*1ll*C(n-m+i-1,i))%P;
		cout<<ans*1ll*qp(qp(2,n-1),P-2)%P*k%P<<'\n';
	}
	return 0;
}