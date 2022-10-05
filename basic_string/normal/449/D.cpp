#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=2e6+7;
int qp(int b){
	int a=2,r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int n=1,a[N],d[N];
void fwt(){
	int i,j,k,l,p;
	for(i=1;i<n;i<<=1)
	for(j=0,l=i<<1;j<n;j+=l)
	for(k=j,p=j+i;k<p;++k)
	a[k]=(a[k]+a[i+k])%P;
}
int main(){
	int m,w=0,s=0,i,j;
	scanf("%d",&m);
	for(i=0;i<m;++i)scanf("%d",&j),++a[j],w=max(w,j);
	while(n<=w)n<<=1;
	fwt(),d[0]=1;
	for(i=0;i<n;++i){
		if(i)d[i]=-d[i^(i&-i)];
		s=(s+d[i]*(qp(a[i])-1))%P;
	}
	printf("%d",(s+P)%P);
	return 0;
}