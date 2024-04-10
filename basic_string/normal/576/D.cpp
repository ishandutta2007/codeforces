#include<bits/stdc++.h>
using namespace std;
const int N=153;
int n,q[N],d[N];
bool f[N];
struct mat{
	bitset<N>a[N];
	mat operator*(mat b){
		mat r;
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)if(a[i][j])r.a[i]|=b.a[j];
		return r;
	}
}a,b,c;
mat qp(mat a,int b){
	mat r=c;
	for(;b;b>>=1,a=a*a)if(b&1)r=r*a;
	return r;
}
struct E{
	int a,b,d;
}e[N];
int main(){
	int m,i,j,k,s=2e9,h,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].d);
	sort(e+1,e+m+1,[](E a,E b){return a.d<b.d;});
	for(i=1;i<=n;++i)c.a[i][i]=1;
	for(i=1,b=c;i<=m;++i){
		b=b*qp(a,e[i].d-e[i-1].d),a.a[e[i].a][e[i].b]=1;
		memset(f+1,0,n),memset(d+1,0,n*4),h=t=0;
		for(j=1;j<=n;++j)if(b.a[1][j])q[++t]=j,f[j]=1;
		for(;h<t;){
			k=q[++h];
			for(j=1;j<=n;++j)if(!f[j]&&a.a[k][j])f[j]=1,d[j]=d[k]+1,q[++t]=j;
		}
		if(f[n])s=min(s,e[i].d+d[n]);
	}
	if(s==2e9)puts("Impossible");else printf("%d",s);
	return 0;
}