#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
enum{N=1000009};
int jc[N],ijc[N];
int C(int n,int m){
	if(n<m||m<0)return 0;
	return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;
}
int a[N],w[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,k,l,m=570000;
	cin>>n;
	jc[0]=1;
	for(i=1;i<N;++i)jc[i]=jc[i-1]*1ll*i%P;
	ijc[N-1]=qp(jc[N-1],P-2);
	for(i=N-1;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	int ans=0;
	for(i=0;i<=n;++i)cin>>a[i];
	if(a[0]==0){cout<<0;return 0;}
	for(i=0;i<=n;++i){
		for(j=a[i+1];j<a[i];++j)w[i+j+1]=(w[i+j+1]+C(i+j,i))%P;
		/*ans=(ans-C(i+j,i)*1ll*C((m-j+m-i-1),m-i-1)%P*
		(m-j+m-i-1)
		)%P;*/
	}
	for(i=0;i<=n;++i)w[i+a[i]]=(w[i+a[i]]+C(i+a[i]-1,i))%P;
//	m=min(m,24);
	for(i=0,j=1;i<=m;++i){
		j=(j-w[i])%P;
	//	cout<<i<<' '<<j<<'!';
		ans=(ans+j)%P;
		j=j*2ll%P;
	}
	cout<<(ans+P)%P;
}