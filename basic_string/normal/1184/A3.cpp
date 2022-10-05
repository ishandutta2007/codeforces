#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=N*3;
char sa[N],sb[N];
int w[N],a[N],n,m;
bool p[M];
int qp(int a,int b,int p){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;
	return r;
}
void wk(int d){
	int p=m/d*d+1,i,j;
	for(i=0;i<d;++i)a[i]=0;
	for(i=0;i<n;++i)j=i%d,a[j]+=w[i];
	while(p<m)p+=d;
	for(;p<M;p+=d)if(!::p[p]){
	gg:;
	int r=qp(rand()%(p-1)+1,(p-1)/d,p),o=1,z;
	if(r<2)goto gg;
	for(i=1;i<=d;++i){
		o=o*1ll*r%p,z=0;
		for(j=d-1;~j;--j)z=(z*1ll*o+a[j])%p;
		if(z==0&&2<=o&&o<=p-2){printf("%d %d",p,o);exit(0);}
	}
}
}
int main(){
	srand(9);
	int i,j;
	scanf("%d%d%s%s",&n,&m,sa,sb);
	for(i=0;i<n;++i)w[i]=sa[i]-sb[i];
	for(i=2;i<M;++i)if(!p[i])for(j=i*2;j<M;j+=i)p[j]=1;
	for(i=2;;++i)if(!p[i])wk(i);
	return 0;
}