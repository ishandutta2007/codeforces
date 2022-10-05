#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int a[N],x[N],y[N],f[N],u,v;
basic_string<int>g[N];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void dfs(int x,int y,int z){
	if(z>u)u=z,v=x;
	for(int i:g[x])if(i!=y)dfs(i,x,z+1);
}
int main(){
	int n,i;
	scanf("%d",&n),iota(f,f+N,0);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i)if(scanf("%d%d",x+i,y+i),a[x[i]]==a[y[i]])f[gf(x[i])]=y[i];
	for(i=1;i<n;++i)if(a[x[i]]!=a[y[i]])g[gf(x[i])]+=gf(y[i]),g[f[y[i]]]+=f[x[i]];
	dfs(gf(1),0,0),u=0,dfs(v,0,0),printf("%d",(u+1)/2);
	return 0;
}