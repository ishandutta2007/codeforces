#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3,M=4e5+3;
int he[N],to[M],ne[M];
ll w[N],f[N],g[N];
bool b[N];
void dfs(int x,int y){
	int i=he[x],j;
	ll o=0,u=0;
	bool z=0;
	for(b[x]=1;i;i=ne[i])if(i!=y){
		j=to[i];
		if(b[j])z=1;
		else{
			dfs(j,i^1);
			if(f[j]>=0)o+=f[j],z=1,u=max(u,g[j]-f[j]);
			else u=max(u,g[j]);
		}
	}
	f[x]=z?o+w[x]:-1,g[x]=o+u+w[x];
}
int main(){
	int n,m,i,j,t=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%lld",w+i);
	while(m--){
		scanf("%d%d",&i,&j);
		ne[++t]=he[i],to[t]=j,he[i]=t;
		ne[++t]=he[j],to[t]=i,he[j]=t;
	}
	scanf("%d",&i),dfs(i,0),printf("%lld\n",g[i]);
	return 0;
}