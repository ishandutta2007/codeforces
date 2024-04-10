#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3,P=1e9+7;
int jc[N],ijc[N],c2[N],*c=c2+1,f[N],w[N],a[N];
bool b[N];
int C(int n,int m){return jc[n]*1ll*ijc[m]%P*ijc[n-m]%P;}
int qp(int a,int b){
	int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
void in(int n){
	int i;
	for(jc[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*1ll*i%P;
	for(ijc[n]=qp(jc[n],P-2),i=n;i;--i)ijc[i-1]=ijc[i]*1ll*i%P;
	for(i=0;i<n;++i)c[i]=(c[i-1]+C(n-1,i))%P;
	for(i=1;i<=n;++i)f[i]=(f[i-1]+0ll+c[n-1]-c[i-1]-c[i-2])%P;
}
int main(){
	int n,i,j,k,l,s=0;
	for(scanf("%d",&n),in(n),i=1;i<=n;++i)scanf("%d",&j),++w[j];
	for(i=2;i<N;++i)if(!b[i]){
		for(j=i;j<N;j+=i)b[j]=1;
		for(j=k=1;k*1ll*i<N;++j){
			for(a[j]=0,k*=i,l=k;l<N;l+=k)a[j]+=w[l];
			if(!a[j])break;
		}
		for(a[j]=0;--j;)s=(s+j*1ll*(f[a[j]]-f[a[j+1]]))%P;
	}
	printf("%d",(s+P)%P);
	return 0;
}