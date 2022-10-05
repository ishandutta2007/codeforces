#include<bits/stdc++.h>
using namespace std;
enum{N=200009,P=998244353};
int jc[N],ijc[N],f[N];
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,w=0;
	for(cin>>n,m=(n+1)/2,jc[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%P;
	for(ijc[n]=qp(jc[n],P-2),i=n;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(i=m;i>1;--i)f[i]=(jc[n-i]*1ll*jc[n-m]%P*ijc[n-m-i+1]+(P-w)*1ll*jc[i-1]%P*ijc[i])%P,w=(w+f[i])%P;
	for(f[1]=f[2],i=1;i<=n;++i)cout<<f[i]<<' ';
}