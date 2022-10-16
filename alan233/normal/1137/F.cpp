// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=400005;

vector<int> adj[N];
int n,q;

struct Fen{
	int c[N];
	void add(int x,int dlt){
		while(x<N)c[x]+=dlt,x+=x&-x;
	}
	int qry(int x){
		int ret=0;
		while(x)ret+=c[x],x^=x&-x;
		return ret;
	}
}fen;

int ch[N][2],fa[N],c[N],sz[N],rt,now;
int tagr[N],tagc[N];// rev, cov

bool Get(int x){
	return ch[fa[x]][1]==x;
}
bool nroot(int x){
	return ch[fa[x]][0]==x||ch[fa[x]][1]==x;
}
void pushup(int u){
	sz[u]=sz[ch[u][0]]+sz[ch[u][1]]+1;
}
void pushrev(int u){
	tagr[u]^=1,swap(ch[u][0],ch[u][1]);
}
void pushcov(int u,int dlt){
	tagc[u]=dlt,c[u]=dlt;
}
void pushdown(int u){
	if(tagr[u])pushrev(ch[u][0]),pushrev(ch[u][1]),tagr[u]=0;
	if(tagc[u])pushcov(ch[u][0],tagc[u]),pushcov(ch[u][1],tagc[u]),tagc[u]=0;
}
void dfs1(int u,int fa){
	::fa[u]=fa;
	for(auto v:adj[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
}
void build(){
	static bool vis[N];
	per(i,n,1){
		int cur=0;
		for(int x=i,y=0;x&&!vis[x];y=x,x=fa[x]){
			c[x]=i,vis[x]=1,ch[x][1]=y,pushup(x);
			++cur;
		}
		fen.add(i,cur);
	}
}
void Rotate(int x){
	int y=fa[x],z=fa[y],k=Get(x);
	if(nroot(y))ch[z][Get(y)]=x;fa[x]=z;
	ch[y][k]=ch[x][k^1];if(ch[x][k^1])fa[ch[x][k^1]]=y;
	ch[x][k^1]=y;fa[y]=x;
	pushup(y),pushup(x);
}
void Splay(int x){
	static stack<int> stk;
	for(int i=x;;i=fa[i]){
		stk.push(i);
		if(!nroot(i))break;
	}
	while(!stk.empty())pushdown(stk.top()),stk.pop();
	for(;nroot(x);Rotate(x)){
		if(nroot(fa[x]))
			Rotate(Get(fa[x])==Get(x)?fa[x]:x);
	}
}
void access(int x,int v){
	int y;
	for(y=0;x;y=x,x=fa[x]){
		Splay(x),fen.add(c[x],-(sz[ch[x][0]]+1)),ch[x][1]=y,pushup(x);
	}
	fen.add(v,sz[y]),pushcov(y,v);
}
void makeroot(int x){
	access(x,c[rt]),fen.add(c[rt],-1);
	Splay(x),pushrev(x),pushdown(x);
	assert(!ch[x][0]);
	ch[x][1]=0,c[rt=x]=++now,fen.add(c[rt],1);
}
int query(int x){
	Splay(x);
	// printf("c[%d]=%d\n",x,c[x]);
	// printf("sz[%d]=%d,sz[rs]=%d\n",x,sz[x],sz[ch[x][1]]);
	return fen.qry(c[x]-1)+sz[ch[x][1]]+1;
}

int main(){
	n=read(),q=read();
	rep(i,1,n-1){
		int u=read(),v=read();
		adj[u].pb(v),adj[v].pb(u);
	}
	dfs1(n,0),build(),rt=now=n;
	while(q--){
		char opt[10];scanf("%s",opt);
		if(opt[0]=='u'){
			int p=read();
			makeroot(p);
		}else if(opt[0]=='w'){
			int u=read();
			print(query(u),'\n');
		}else{
			int u=read(),v=read();
			print(query(u)<query(v)?u:v,'\n');
		}
		// rep(i,1,n){
		// 	printf("query(%d)=%d\n",i,query(i));
		// }
	}
	return 0;
}