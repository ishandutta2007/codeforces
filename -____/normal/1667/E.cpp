#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1<<19;
const int MO = 998244353;
int ad(int x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
	return x;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
void DFT(int C[],int n,int fl){
	int i,j,k,l;
	int u,v,w,cur;
	i=n>>1;
	for(j=1;j<n;j=j+1){
		if(i<j)
			swap(C[i],C[j]);
		for(k=n>>1;i&k;k>>=1)
			i^=k;
		i^=k;
	}
	for(l=2;l<=n;l<<=1){
		w=fpow(3,(MO-1)/l);
		if(fl==-1)
			w=fpow(w);
		for(i=0;i<n;i=i+l){
			cur=1;
			for(j=i;j<i+(l>>1);j=j+1){
				u=C[j],v=mul(C[j+(l>>1)],cur);
				C[j]=ad(u,v),C[j+(l>>1)]=ad(u,MO-v);
				cur=mul(cur,w);
			}
		}
	}
}
int m,A[N],B[N],C[N];
void FFT(){
	int i,l,o;
	for(l=1;l<m+m;l<<=1);
	DFT(A,l,1);
	DFT(B,l,1);
	for(i=0;i<l;i=i+1)
		C[i]=mul(A[i],B[i]);
	DFT(C,l,-1);
	o=fpow(l);
	for(i=0;i<l;i=i+1)
		C[i]=mul(C[i],o),A[i]=0,B[i]=0;
}
int n,f[N],g[N],d[N],e[N];
int main(){
	int i,x;
	scanf("%d",&n);
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=mul(f[i-1],i);
	g[n]=fpow(f[n]);
	for(i=n;i>=1;i--)
		g[i-1]=mul(g[i],i);
	m=n;
	for(i=n/2;i<=n;i++)
		A[i-n/2]=g[n-i];
	for(i=n/2;i<n-1;i++)
		B[n-i]=f[n-i-2];
	FFT();
	for(i=2;i<=n/2+1;i++)
		d[i]=mul(C[i+n/2+1],mul(f[n-i],i-1));
	d[1]=f[n-1];
	x=0;
	for(i=n;i>=1;i--){
		e[i]=ad(d[i],MO-x);
		x=ad(x,mul(d[i],fpow(i-1)));
	}
	for(i=1;i<=n;i++)
		printf("%d ",e[i]);
	return 0;
}