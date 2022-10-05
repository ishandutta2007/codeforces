#include<bits/stdc++.h>
using namespace std;
const int O=2e5,N=4e5+3,M=8e5+3;
int he[N],to[M],ne[M],d[N],t=1;
bool b[N],f[N],g[N];
void add(int x,int y){
	ne[++t]=he[x],to[t]=y,he[x]=t;
	ne[++t]=he[y],to[t]=x,he[y]=t;
}
void dfs(int x){
	b[x]=1;
	for(int i,j;i=he[x];)if(he[x]=ne[i],!f[j=i>>1])f[j]=1,dfs(to[i]),g[j]=i&1;
}
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&j,&k),k+=O,add(j,k),++d[j],++d[k];
	}
	for(i=1,j=0;i<N;++i)if(d[i]&1){
		if(j)add(j,i),j=0;
		else j=i;
	}
	for(i=1;i<N;++i)if(!b[i])dfs(i);
	for(i=1;i<=n;++i)putchar(g[i]?'b':'r');
	return 0;
}