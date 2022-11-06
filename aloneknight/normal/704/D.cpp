#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200300,M=N*5,K=100005,inf=1e9;
char res[N];
inline int rd()
{
	int x=0;char c=getchar();while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();return x;
} 
//dinic 
int tt,cc=1,S,T,hd[N],iter[N],dis[N],q[N];
struct E{int v,nxt,w,i;}e[M];
inline void fail(){puts("-1");exit(0);}
inline void addedge(int u,int v,int w,int i){e[++cc]=(E){v,hd[u],w,i};hd[u]=cc;e[++cc]=(E){u,hd[v],0,i};hd[v]=cc;}
inline bool bfs(int S,int T)
{
	memset(dis,-1,sizeof(dis));memcpy(iter,hd,sizeof(hd));
	int ql=0,qr=0;q[++qr]=S;dis[S]=0;
	while(ql<qr)
	{
		int x=q[++ql];
		for(int i=hd[x];i;i=e[i].nxt)if(e[i].w&&dis[e[i].v]==-1){dis[e[i].v]=dis[x]+1;q[++qr]=e[i].v;}
	}
	return ~dis[T]; 
}
int dfs(int x,int T,int f)
{
	if(x==T||!f)return f;
	int sf=0;
	for(int&i=iter[x];i;i=e[i].nxt)if(e[i].w&&dis[e[i].v]==dis[x]+1)
	{
		int w=dfs(e[i].v,T,min(f,e[i].w));
		if(w)
		{
			e[i].w-=w;e[i^1].w+=w;f-=w;sf+=w;
			if(!f)break;
		}
	}
	return sf;
}
int dinic(int S,int T){int f=0;while(bfs(S,T))f+=dfs(S,T,inf);return f;}
//flow with limits
int SS,TT,s[N];
inline void add(int u,int v,int a,int b,int i){if(a>b)fail();addedge(u,v,b-a,i);s[u]-=a;s[v]+=a;}
int sol()
{
	for(int i=1;i<=tt;i++)if(s[i]>0)addedge(SS,i,s[i],0);else if(s[i]<0)addedge(i,TT,-s[i],0);
	addedge(T,S,inf,0);dinic(SS,TT);int ee=cc;
	for(int i=hd[SS];i;i=e[i].nxt)if(e[i].w)fail();
	hd[S]=e[hd[S]].nxt;hd[T]=e[hd[T]].nxt;return dinic(S,T)+e[ee].w; 
}
//get an answer
inline void calc(int o,int l,int r){for(int x=1;x<l;x++)for(int i=hd[x];i;i=e[i].nxt)if(e[i].v>=l&&e[i].v<=r)res[e[i].i]=o^e[i].w?'b':'r';}
int n,m,r,b,o,nx,ny,x[K],y[K],ox[K],oy[K],sx[K],sy[K],mxx[K],mxy[K];
int main()
{
	n=rd();m=rd();r=rd();b=rd();;if(r>b)swap(r,b),o=1;
	for(int i=1;i<=n;i++)ox[i]=x[i]=rd(),oy[i]=y[i]=rd();
	sort(ox+1,ox+n+1);nx=unique(ox+1,ox+n+1)-ox-1;
	sort(oy+1,oy+n+1);ny=unique(oy+1,oy+n+1)-oy-1;
	for(int i=1;i<=n;i++)x[i]=lower_bound(ox+1,ox+nx+1,x[i])-ox,sx[x[i]]++;
	for(int i=1;i<=n;i++)y[i]=lower_bound(oy+1,oy+ny+1,y[i])-oy,sy[y[i]]++;
	for(int i=1;i<=n;i++)mxx[i]=mxy[i]=n;
	for(int i=1,t,l,d,p;i<=m;i++)
	{
		t=rd()-1;l=rd();d=rd();
		if(!t)p=lower_bound(ox+1,ox+nx+1,l)-ox;else p=lower_bound(oy+1,oy+ny+1,l)-oy;
		if((!t&&ox[p]!=l)||(t&&oy[p]!=l))continue;
		if(!t)mxx[p]=min(mxx[p],d);else mxy[p]=min(mxy[p],d);
	} 
	S=nx+ny+1;T=S+1;SS=T+1;TT=tt=SS+1;
	for(int i=1;i<=n;i++)add(x[i],nx+y[i],0,1,i);
	for(int i=1;i<=nx;i++)
	{
		int l=0,r=inf;
		if(!mxx[i]&&(sx[i]&1)){puts("-1");return 0;}
		if(mxx[i]<sx[i])l=(sx[i]-mxx[i]+1)/2,r=(sx[i]+mxx[i])/2;
		add(S,i,l,r,0);
	}
	for(int i=1;i<=ny;i++)
	{
		int l=0,r=inf;
		if(!mxy[i]&&(sy[i]&1)){puts("-1");return 0;}
		if(mxy[i]<sy[i])l=(sy[i]-mxy[i]+1)/2,r=(sy[i]+mxy[i])/2;
		add(nx+i,T,l,r,0);
	}
	int ans=sol();calc(o,nx+1,nx+ny);
	printf("%lld\n",1ll*ans*r+1ll*(n-ans)*b);
	for(int i=1;i<=n;i++)putchar(res[i]);return 0;
}