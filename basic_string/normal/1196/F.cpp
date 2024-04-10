#include<bits/stdc++.h>
using namespace std;
const int N=809;
struct E{
	int u,v,w;
	bool operator<(E a)const{return w<a.w;}
}e[300009];
int id[200009];
long long d[N][N],a[1000009];
int main(){
	int n,m,o,i,j,k,t=0;
	scanf("%d%d%d",&n,&m,&o),memset(d,63,sizeof d);
	for(i=1;i<=m;++i)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1);
	for(i=1;i<=o;++i){
		if(!id[e[i].u])id[e[i].u]=++t;
		if(!id[e[i].v])id[e[i].v]=++t;
		j=id[e[i].u],k=id[e[i].v],d[j][k]=d[k][j]=e[i].w;
	}
	for(i=1;i<=t;++i)for(j=1;j<=t;++j)for(k=1;k<j;++k)d[j][k]=d[k][j]=min(d[j][k],d[j][i]+d[i][k]);
	k=0;
	for(i=1;i<=t;++i)for(j=1;j<i;++j)a[++k]=d[i][j];
	sort(a+1,a+k+1),printf("%lld",a[o]);
	return 0;
}