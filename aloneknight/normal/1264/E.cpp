#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
const int N=105,M=100005;
int n,m,S,T,cnt,cc=1,flw,cst,ans,d[N],a[N][N],res[N][N],hd[M],vis[M],pre[M],dis[M],q[M];
struct E{int v,nxt,w,c;}e[M];
inline void add(int u,int v,int w,int c){e[++cc]=(E){v,hd[u],w,c};hd[u]=cc;e[++cc]=(E){u,hd[v],0,-c};hd[v]=cc;}
inline bool spfa()
{
	for(int i=0;i<=cnt;i++)pre[i]=0,dis[i]=1e9+7;
	int ql=0,qr=0;q[++qr]=S;dis[S]=0;
	while(ql<qr)
	{
		int x=q[++ql];vis[x]=0;
		for(int i=hd[x],y;i;i=e[i].nxt)if(e[i].w&&dis[x]+e[i].c<dis[y=e[i].v])
		{
			dis[y]=dis[x]+e[i].c;pre[y]=i;
			if(!vis[y])q[++qr]=y,vis[y]=1;
		}
	}
	return pre[T];
}
inline void mcmf()
{
	while(spfa())
	{
		int mn=1e9;for(int i=pre[T];i;i=pre[e[i^1].v])mn=min(mn,e[i].w);flw+=mn;
		for(int i=pre[T];i;i=pre[e[i^1].v])e[i].w-=mn,e[i^1].w+=mn;cst+=dis[T]*mn;
	}
}
int main()
{
	scanf("%d%d",&n,&m);ans=n*(n-1)*(n-2)/6;
	rep(i,1,m)
	{
		int u,v;scanf("%d%d",&u,&v);ans-=d[u];
		d[u]++;res[u][v]=1;a[u][v]=a[v][u]=-1;
	}
	cnt=n*2;S=++cnt;T=++cnt;
	rep(i,1,n)rep(j,i+1,n)if(~a[i][j])
	{
		a[i][j]=a[j][i]=++cnt;add(S,a[i][j],1,0);
		add(a[i][j],i,1,0);add(a[i][j],j,1,0);
	}
	rep(i,1,n)rep(j,1,n)add(i,i+n,1,d[i]+j-1);
	rep(i,1,n)add(i+n,T,n,0);
	mcmf();ans-=cst;
	rep(i,1,n)rep(j,i+1,n)if(~a[i][j])for(int k=hd[a[i][j]];k;k=e[k].nxt)if(e[k].v!=S&&!e[k].w)res[e[k].v][i^j^e[k].v]=1;
	rep(i,1,n)
	{
		rep(j,1,n)printf("%d",res[i][j]);
		puts("");
	}
	return 0;
}