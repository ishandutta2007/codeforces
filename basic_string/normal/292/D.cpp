#include<bits/stdc++.h>
using namespace std;
const int N=509,M=10009;
int x[M],y[M],f[M][N],g[M][N],h[N];
int gf(int*f,int x){return f[x]==x?x:f[x]=gf(f,f[x]);}
int main(){
	int n,m,q,i,j,l,r,s;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i);
	for(i=1;i<=n;++i)f[0][i]=g[m+1][i]=i;
	for(i=1;i<=m;++i){
		memcpy(f[i],f[i-1],n*4+4);
		f[i][gf(f[i],x[i])]=gf(f[i],y[i]);
	}
	for(i=m;i;--i){
		memcpy(g[i],g[i+1],n*4+4);
		g[i][gf(g[i],x[i])]=gf(g[i],y[i]);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r),s=0;
		memcpy(h,f[l-1],n*4+4),++r;
		for(i=1;i<=n;++i)h[gf(h,i)]=gf(h,g[r][i]);
		for(i=1;i<=n;++i)if(h[i]==i)++s;
		printf("%d\n",s);
	}
	return 0;
}