#include<bits/stdc++.h>
using namespace std;
const int N=1<<12,M=N|1,P=7340033;
int a[31][M],b[M],r[M];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
void ntt(int*a,bool b){
	int i,j,k,l,p,u,v,x,y;
	for(i=0;i<N;++i)if(i<r[i])swap(a[i],a[r[i]]);
	for(i=1;i<N;i<<=1)
	for(u=qp(b?3:2446678,(P-1)/(l=i<<1)),j=0;j<N;j+=l)
	for(v=1,k=j,p=i+j;k<p;++k,v=v*1ll*u%P)
	x=a[k],y=v*1ll*a[i+k]%P,a[k]=(a[k]=x+y)<P?a[k]:a[k]-P,a[i+k]=x<y?x-y+P:x-y;
}
int main(){
	int i,j,q;
	for(i=0;i<N;++i)r[i]=(r[i>>1]>>1)|((i&1)<<11);
	for(i=a[0][0]=1;i<29;++i){
		memset(b,0,M*4),memcpy(b,a[i-1],N),ntt(b,1);
		for(j=0;j<N;++j)q=b[j]*1ll*b[j]%P,b[j]=q*1ll*q%P;
		ntt(b,0);
		for(j=0;j<N;++j)b[j]=b[j]*7338241ll%P;
		a[i][0]=1,memcpy(a[i]+1,b,N);
	}
	for(scanf("%d",&q);q--;)scanf("%d%d",&i,&j),i-=(1<<__lg(i))-1,printf("%d\n",a[__lg(i&-i)][j]);
	return 0;
}