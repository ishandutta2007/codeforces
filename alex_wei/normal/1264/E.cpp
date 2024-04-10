#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef unsigned long long ull;
typedef pair <long long,long long> pll;

#define fi first
#define se second
#define gc getchar()
#define pb emplace_back
#define mem(x,v,n) memset(x,v,sizeof(x[0])*n)
#define cpy(x,y,n) memcpy(x,y,sizeof(x[0])*n)

const ld Pi=acos(-1);
const ll mod=998244353;

inline ll read(){
    ll x=0; bool sign=0; char s=gc;
    while(!isdigit(s))sign|=s=='-',s=gc;
    while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
    return sign?-x:x;
}

const int N=2e3+5;
const int M=2e4+5;

int node,cnt=1,deg[N],e[N>>5][N>>5];
int hd[N],nxt[M],to[M],lim[M],cst[M];
void add(int u,int v,int w,int c){
	nxt[++cnt]=hd[u];
	hd[u]=cnt,to[cnt]=v;
	lim[cnt]=w,cst[cnt]=c;
}
void adde(int u,int v,int w,int c){
	add(u,v,w,c);
	add(v,u,0,-c);
}

int n,m,x[N],y[N],h[N],vis[N],dis[N],pe[N],pn[N];
void spfa(){
	queue <int> q;
	mem(h,0x3f,N);
	h[0]=0,q.push(0);
	while(!q.empty()){
		int t=q.front(); q.pop();
		vis[t]=0;
		for(int i=hd[t];i;i=nxt[i]){
			int it=to[i];
			if(lim[i]&&h[t]+cst[i]<h[it]){
				h[it]=h[t]+cst[i];
				if(!vis[it])vis[it]=1,q.push(it);
			}
		}
	}
}
bool dij(){
	priority_queue <pii,vector<pii>,greater<pii>> q;
	mem(dis,0x3f,N),mem(vis,0,N),dis[0]=0,q.push({0,0});
	while(!q.empty()){
		pii t=q.top(); q.pop();
		int id=t.se,ds=t.fi;
		if(vis[id])continue;
		vis[id]=1;
		for(int i=hd[id];i;i=nxt[i]){
			int it=to[i],w=cst[i]+h[id]-h[it];
			if(lim[i]&&ds+w<dis[it]){
				dis[it]=ds+w,pn[it]=id,pe[it]=i;
				if(!vis[it])q.push({dis[it],it});
			}
		}
	}
	return dis[n+1]<=1e9;
}
int main(){
	cin>>n>>m,node=n+1;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		deg[u]++,e[u][v]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(!e[i][j]&&!e[j][i]&&i<j){
				node++,x[node]=i,y[node]=j;
				adde(0,node,1,0);
				adde(node,i,1,0);
				adde(node,j,1,0);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++)
			if(deg[i]<=j)
				adde(i,n+1,1,j);
	spfa();
	while(dij()){
		for(int i=0;i<=node;i++)h[i]+=dis[i];
		int fl=1e9;
		for(int i=n+1;i;i=pn[i])fl=min(fl,lim[pe[i]]);
		for(int i=n+1;i;i=pn[i])lim[pe[i]]-=fl,lim[pe[i]^1]+=fl;
	}
	for(int id=n+2;id<=node;id++){
		for(int i=hd[id];i;i=nxt[i]){
			if(to[i]==x[id])e[x[id]][y[id]]=!lim[i];
			else if(to[i]==y[id])e[y[id]][x[id]]=!lim[i];
		}
	}
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=n;j++)
			if(e[i][j]!=2)cout<<e[i][j];
			else 
    return 0;
}