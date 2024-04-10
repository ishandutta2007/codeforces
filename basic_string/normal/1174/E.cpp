#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int a[21],b[21],c[21],d[21],u[21],v[21];
int main(){
	int n,m,i,j,*f=a,*g=b,*p=c,*q=d;
	scanf("%d",&n),m=__lg(n);
	f[m]=1;
	if(m&&((1<<m-1)*3)<=n)g[m-1]=1;
	for(i=m;~i;--i)u[i]=n/(1<<i),v[i]=n/((1<<i)*3);
	for(i=1;i<n;++i){
		swap(f,p),swap(g,q);
		memset(f,0,84),memset(g,0,84);
		for(j=m;j;--j){
			f[j-1]=(f[j-1]+p[j]*1ll*(u[j-1]-u[j]))%P;
			g[j-1]=(g[j-1]+q[j]*1ll*(v[j-1]-v[j]))%P;
		}
		for(j=m;~j;--j){
			f[j]=(f[j]+p[j]*1ll*max(u[j]-i,0)+q[j]*1ll*(u[j]-v[j]))%P;
			g[j]=(g[j]+q[j]*1ll*max(v[j]-i,0))%P;
		}
	}
	printf("%d",(f[0]+P)%P);
	return 0;
}