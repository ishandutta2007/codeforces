#include<bits/stdc++.h>
using namespace std;
const int N=2009,M=1e6+3;
int a[N],b[N],c[N],d[N],e[M],f[N],g[N],h[M];
int main(){
	int n,m,i,j,p=0,s=1e9;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
	for(j=1;j<=m;++j)scanf("%d%d",c+j,d+j),e[c[j]]=max(e[c[j]],d[j]+1);
	for(i=M-1;~i;--i)e[i]=max(e[i],e[i+1]);
	f[++p]=0,g[p]=e[0];
	for(i=1;i<M;++i)if(e[i]!=e[i-1])f[++p]=i,g[p]=e[i];
	for(i=1;i<=n;++i){
		for(j=2;j<=p;++j){
			if(f[j]<a[i])continue;
			if(g[j-1]>=b[i])h[f[j]-a[i]-1]=max(h[f[j]-a[i]-1],g[j-1]-b[i]);
		}
	}
	for(i=M-2;~i;--i)h[i]=max(h[i],h[i+1]),s=min(s,h[i]+i);
	printf("%d",s);
	return 0;
}