#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,fa[N],nxt[N],vis[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void link(int x,int y){fa[find(x)]=find(y);}
int main()
{
	scanf("%d",&n);
	if(n&1)return puts("-1"),0;
	for(int i=0;i<n;i++)fa[i]=i;
	for(int i=0;i<n/2;i++)nxt[i]=1;
	for(int i=0;i<n;i++)link(i,(2*i+nxt[i])%n);
	for(int i=0;i<n/2;i++)if(find(i)!=find(i+n/2))
		nxt[i]^=1,nxt[i+n/2]^=1,link(i,i+n/2);
	int u=0;
	while(!vis[u])printf("%d ",u),vis[u]=1,u=(2*u+nxt[u])%n;
	puts("0");
	return 0;
}