#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
double a[N],u[N],v[N],w[N],ff[N],gg[N],y[N];
int q[N];
double sl(int i,int j){return(y[j]-y[i])/(u[j]-u[i]);}
int main(){
	int n,m,i,j,l,r;
	double*f=ff,*g=gg;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%lf",a+i),u[i]=u[i-1]+a[i],v[i]=v[i-1]+1/a[i],g[i]=w[i]=w[i-1]+u[i]/a[i];
	for(;--m;swap(f,g))for(i=1,l=r=0;i<=n;++i){
		while(l<r&&sl(q[l],q[l+1])<v[i])++l;
		j=q[l],f[i]=g[j]+w[i]-w[j]-(v[i]-v[j])*u[j],y[i]=g[i]-w[i]+v[i]*u[i];
		while(l<r&&sl(q[r-1],q[r])>=sl(q[r],i))--r;
		q[++r]=i;
	}
	printf("%.9lf",g[n]);
	return 0;
}