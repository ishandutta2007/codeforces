#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define ll long long
#define N 300105
using namespace std;
int n,q,a,b,x,y,k,head[N],cnt,dep[N],fa[N][30];
struct node{
	int to,nxt;
	node(){}
	node(int a,int b){to = a;nxt = b;}
}e[N]; 
void add(int u,int v){
	e[++cnt] = node(v,head[u]);
	head[u] = cnt;
}
void dfs(int u,int f){
	fa[u][0] = f;dep[u] = dep[f]+1;
	for(int i = 1; (1<<i) <= dep[u];++i) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = head[u];~i;i = e[i].nxt){
		if(e[i].to != f) dfs(e[i].to,u);
	} 
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int t = dep[u]-dep[v];
	for(int i = 0;i < 25;++i){
		if((1 & (t >> i)) == 1) u = fa[u][i];
	}
	if(u == v) return u;
	for(int i = 25; i >= 0; --i){
		if(fa[u][i] != fa[v][i]){
			u = fa[u][i];
			v = fa[v][i]; 
		}
	}
	return fa[u][0];
}
int dis(int u,int v){
	int tl = lca(u,v);
	return dep[u]+dep[v]-2*dep[tl];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int u,v,i = 1;i <= n-1;++i){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	} 
	dfs(1,0);
	scanf("%d",&q);
	for(int i = 1;i <= q;++i){
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		int d1,d2,d3;
		bool flag = 0;
		d1 = dis(a,b);d2 = dis(a,x)+dis(b,y)+1;d3 = dis(a,y)+dis(b,x)+1;
		if(d1 <= k&&(d1%2)==(k%2)) flag = 1;
		if(d2 <= k&&(d2%2)==(k%2)) flag = 1;
		if(d3 <= k&&(d3%2)==(k%2)) flag = 1;
		if(flag) puts("YES");
		else puts("NO");
	}
    return 0;
}