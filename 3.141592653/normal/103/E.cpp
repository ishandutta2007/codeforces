#include<bits/stdc++.h>
typedef long long ll;
const ll INF=1e9,INFF=1e14;
inline ll min(ll x,ll y){return x<y?x:y;}
namespace Network
{
	struct edg{int p,t;ll l;}e[1111111];
	int S,T,h[1111111],th[1111111],tot=1,ct;
	ll val[1111111];
	void __ins(int x,int y,ll l){e[++tot]=(edg){h[x],y,l},h[x]=tot;}
	void ins(int x,int y,ll l){__ins(x,y,l),__ins(y,x,0);}
	int dep[1111111];
	bool bfs()
	{
		std::queue<int>q;
		register int i;
		for(i=1;i<=T;i++)dep[i]=0,th[i]=h[i];
		for(q.push(S),dep[S]=1;q.size();)
		{
			int p=q.front();q.pop();
			for(i=h[p];i;i=e[i].p)
			{
				int t=e[i].t;
				if(dep[t]||!e[i].l)continue;
				dep[t]=dep[p]+1,q.push(t);
			}
		}return dep[T];
	}
	ll dfs(int p=S,ll f=INFF)
	{
		if(p==T)return f;
		ll r=0;
		for(register int&i=th[p];i;i=e[i].p)
		{
			int t=e[i].t;
			if(dep[t]!=dep[p]+1||!e[i].l)continue;
			ll g=dfs(t,min(f,e[i].l));
			e[i].l-=g,e[i^1].l+=g,r+=g,f-=g;
			if(!f)break;
		}return r;
	}
	void init(){S=++ct,T=++ct;}
	ll flow()
	{
		ll ret=0;
		for(;bfs();)ret+=dfs();
		return ret;
	}
}
int n;
int main()
{
	scanf("%d",&n);
	Network::ct=n*2,Network::init();
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		for(ii=k;ii;ii--)
		{
			int t;
			scanf("%d",&t);
			Network::ins(i,t+n,INFF);
		}
	}ll ans=0;
	for(i=1;i<=n;i++)
	{
		int val;scanf("%d",&val);
		Network::ins(Network::S,i,INF-val),ans+=val,Network::ins(i+n,Network::T,INF);
	}printf("%lld\n",ans+Network::flow()-INF*n);
}
/*
Please don't let me down.
*/