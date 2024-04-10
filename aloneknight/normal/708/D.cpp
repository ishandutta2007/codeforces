#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
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
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=100005,inf=1<<30;
int n,m,cc,S,T,ans,s[N],hd[N],dis[N],pre[N],vis[N];
struct E{int v,nxt,w,c;}e[N];
inline void add(int u,int v,int w,int c){e[++cc]=(E){v,hd[u],w,c};hd[u]=cc;e[++cc]=(E){u,hd[v],0,-c};hd[v]=cc;}
inline bool spfa()
{
	rep(i,S,T)dis[i]=inf,pre[i]=0;
	queue<int>q;dis[S]=0;q.push(S);vis[S]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=0;
		for(int i=hd[x],y;i;i=e[i].nxt)if(e[i].w&&dis[y=e[i].v]>dis[x]+e[i].c)
		{
			dis[y]=dis[x]+e[i].c;pre[y]=i;
			if(!vis[y])q.push(y),vis[y]=1;
		}
	}
    return dis[T]<inf;
}
int main()
{
	n=rd();m=rd();S=0;T=n+1;cc=1;
	rep(i,1,m)
	{
		int u=rd(),v=rd(),c=rd(),f=rd();
		if(c<f)
		{
			ans+=f-c;s[u]+=f;s[v]-=f;
			add(v,u,f-c,0);add(v,u,c,1);add(u,v,inf,2);
		}
		else
		{
            s[u]+=f;s[v]-=f;
            add(u,v,c-f,1);add(u,v,inf,2);add(v,u,f,1);
		}
	}
	add(n,1,inf,0);
	rep(i,1,n)if(s[i]>=0)add(i,T,s[i],0);else add(S,i,-s[i],0);
    while(spfa())
    {
    	int f=inf;for(int i=T;i!=S;i=e[pre[i]^1].v)f=min(f,e[pre[i]].w);
    	ans+=dis[T]*f;for(int i=T;i!=S;i=e[pre[i]^1].v)e[pre[i]].w-=f,e[pre[i]^1].w+=f;
	}
    printf("%d\n",ans);return 0;
}