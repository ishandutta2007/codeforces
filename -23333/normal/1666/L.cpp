//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#define N 400009
using namespace std;
#define ll long long
int head[N],tag[N],fa[N],n,m,s;
int st[N],top,tot;
int nowtag1,nowtag2;
struct edge{
	int n,to;
}e[N<<1];
int nowtag=0,anstag=0;
inline void add(int u,int v){
	e[++tot].n=head[u];
	e[tot].to=v;
	head[u]=tot; 
}
void dfs(int u){
	for(int i=head[u];i;i=e[i].n){
		int v=e[i].to;
		if(tag[v]==-1)continue;
		if(tag[v]==0){
			tag[v]=nowtag;
		}
		else if(tag[v]!=nowtag){
			anstag=1;
			nowtag1=v;
			nowtag2=u;
			break;
		}
		else continue;
		fa[v]=u;
		dfs(v);
		if(anstag)break;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	tag[s]=-1;
	for(int i=head[s];i;i=e[i].n){
		int v=e[i].to;
	//	cout<<v<<" "<<tag[v]<<endl;
		nowtag=v;
		if(tag[v]==0){
			tag[v]=nowtag;
		}
		else{
			anstag=1;
			nowtag1=v;
			nowtag2=s;
			break;
		}
		fa[v]=s;
		dfs(v);
		if(anstag)break;
	}
	if(anstag){
		puts("Possible");
		int now=nowtag1;
		while(now!=0){
			st[++top]=now;
			now=fa[now];
		}
		printf("%d\n",top);
		for(int i=top;i>=1;--i)printf("%d ",st[i]);
		puts("");
		top=0;
		now=nowtag2;
		st[++top]=nowtag1;
		while(now!=0){
			st[++top]=now;
			now=fa[now];
		}
		printf("%d\n",top);
		for(int i=top;i>=1;--i)printf("%d ",st[i]);
		puts("");
	}
	else{
		puts("Impossible");
	}
	return 0;
}