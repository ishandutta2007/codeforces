#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int x[N],y[N],tp,w[29],g[N];
void work2(int a,int l,int t){
	if(t>1)work2(a,l,t/2),work2(a+t,l,t/2);
	for(int i=0;i<t;++i)x[++tp]=a+l+i,y[tp]=a+l+i+t;
}
void work(int a,int n){
	if(n==1)return;
	int i,j=n,l=2,r,k,t=0,p=0;
	for(;j;j>>=1)if(j&1)w[++t]=1;else ++t;
	for(i=2;i<=t;++i)if(w[i]){
		work2(a,l,1<<i-2),l+=(1<<(i-1));
	}
	g[p++]=1,x[++tp]=a+1,y[tp]=a+n,g[p++]=n,r=n-1,l=2;
	for(i=2;i<t;++i){
		if(w[i]){
			k=p;
			for(j=0;j<k;++j)x[++tp]=a+g[j],y[tp]=a+l+j,g[p++]=l+j;
			l+=k;
		}else{
			k=p;
			for(j=0;j<k;++j)x[++tp]=a+g[j],y[tp]=a+r-j,g[p++]=r-j;
			r-=k;
		}
	}
}
void pre(int a,int n){
	if(n&1)work(a,n);
	else{
		int m=n/2,i;
		pre(a,m),pre(a+m,m);
		for(i=1;i<=m;++i)x[++tp]=a+i,y[tp]=a+m+i;
	}
}
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	pre(0,n);
	printf("%d\n",tp);
	for(i=1;i<=tp;++i)printf("%d %d\n",x[i],y[i]);
	return 0;
}