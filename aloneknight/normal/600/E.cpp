#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
inline int rd()
{
	int x=0;char c=getchar();while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();return x;
}
const int N=100005;
int n,cc,mx,a[N],hd[N],sz[N],hs[N],vis[N],c0[N],c1[N];ll c2[N],ans[N];
struct E{int v,nxt;}e[N*2];
inline void add(int u,int v){e[++cc]=(E){v,hd[u]};hd[u]=cc;}
void dfs1(int x,int p)
{
	sz[x]=1;
	for(int i=hd[x];i;i=e[i].nxt)
	{
		int y=e[i].v;if(y==p)continue;
		dfs1(y,x);sz[x]+=sz[y];
		if(sz[y]>sz[hs[x]])hs[x]=y;
	}
}
void upd(int x,int p,int v)
{
	int&t=c0[a[x]];c1[t]--;c2[t]-=a[x];t+=v;c1[t]++;c2[t]+=a[x];
	if(v>0)mx=max(mx,t);else if(!c1[mx])mx--;
	for(int i=hd[x],y;i;i=e[i].nxt)if((y=e[i].v)!=p&&!vis[y])upd(y,x,v);
}
void dfs2(int x,int p,int o)
{
	for(int i=hd[x],y;i;i=e[i].nxt)if((y=e[i].v)!=p&&y!=hs[x])dfs2(y,x,0);
	if(hs[x])dfs2(hs[x],x,1),vis[hs[x]]=1;
	upd(x,p,1);ans[x]=c2[mx];vis[hs[x]]=0;
	if(!o)upd(x,p,-1);
}
int main()
{
	n=rd();rep(i,1,n)a[i]=rd();
	rep(i,1,n-1){int u=rd(),v=rd();add(u,v);add(v,u);}
	dfs1(1,0);dfs2(1,0,1);
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}