#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3;
int he[N],to[N*2],ne[N*2],sz[N],n;
ll s,g[N];
void dfs(int x,int y){
	sz[x]=1; 
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y)dfs(j,x),sz[x]+=sz[j],g[x]+=g[j];
	g[x]+=sz[x];
}
void dfs(int x,int y,ll z){
	if(z>s)s=z;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y)dfs(j,x,n-sz[j]*2+z);
}
int main(){
	int i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs(1,0),dfs(1,0,g[1]),printf("%lld",s);
	return 0;
}