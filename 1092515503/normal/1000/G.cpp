#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,val[300100],f[300100],head[300100],cnt;
struct node{
	int to,next,val,dis;
}edge[600100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
void dfs1(int x,int fa){
	f[x]=val[x];
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs1(edge[i].to,x),edge[i].dis=max(0ll,f[edge[i].to]-2*edge[i].val),f[x]+=edge[i].dis;
}
void dfs2(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)edge[i^1].dis=max(0ll,f[x]-max(0ll,f[edge[i].to]-2ll*edge[i].val)-2ll*edge[i].val),f[edge[i].to]+=edge[i^1].dis,dfs2(edge[i].to,x);
}
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct LCT{
	int fa,ch[2],sum,val;
	bool rev;
}t[600100];
inline int identify(int x){
	if(x==t[t[x].fa].ch[0])return 0;
	if(x==t[t[x].fa].ch[1])return 1;
	return -1;
}
inline void pushup(int x){
	t[x].sum=t[x].val;
	if(lson)t[x].sum+=t[lson].sum;
	if(rson)t[x].sum+=t[rson].sum;
}
inline void REV(int x){t[x].rev^=1,swap(lson,rson);}
inline void pushdown(int x){
	if(!t[x].rev)return;
	if(lson)REV(lson);
	if(rson)REV(rson);
	t[x].rev=0;
}
inline void rotate(int x){
	register int y=t[x].fa,z=t[y].fa,dirx=identify(x),diry=identify(y),b=t[x].ch[!dirx];
	if(diry!=-1)t[z].ch[diry]=x;t[x].fa=z;
	if(b)t[b].fa=y;t[y].ch[dirx]=b;
	t[y].fa=x,t[x].ch[!dirx]=y;
	pushup(y),pushup(x);
}
inline void pushall(int x){if(identify(x)!=-1)pushall(t[x].fa);pushdown(x);}
inline void splay(int x){for(pushall(x);identify(x)!=-1;rotate(x))if(identify(t[x].fa)!=-1)rotate(identify(x)==identify(t[x].fa)?t[x].fa:x);}
inline void access(int x){for(register int y=0;x;x=t[y=x].fa)splay(x),rson=y,pushup(x);}
inline void makeroot(int x){access(x),splay(x),REV(x);}
inline int split(int x,int y){makeroot(x),access(y),splay(y);return t[y].sum;}
inline void link(int x,int y){makeroot(x),t[x].fa=y;}
signed main(){
	scanf("%lld%lld",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,x,y,z;i<n;i++)scanf("%lld%lld%lld",&x,&y,&z),ae(x,y,z);
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)t[i].val=f[i];
	for(int i=0,x;i<cnt;i+=2)x=edge[i].dis+edge[i+1].dis+edge[i].val,t[n+(i>>1)+1].val=-x,link(edge[i].to,n+(i>>1)+1),link(edge[i^1].to,n+(i>>1)+1);
	for(int i=1,x,y;i<=m;i++)scanf("%lld%lld",&x,&y),printf("%lld\n",split(x,y));
//	for(int i=1;i<=n;i++)printf("%lld ",f[i]);puts("");
//	for(int i=1;i<=n;i++)dfs1(i,0),printf("%lld ",f[i]);puts("");
	return 0;
}