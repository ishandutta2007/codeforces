#include <bits/stdc++.h>
using namespace std;
#define rint register ll
#define IL inline
#define rep(i,h,t) for(ll i=h;i<=t;i++)
#define dep(i,t,h) for(ll i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define mep(x,y) memcpy(x,y,sizeof(y))
#define mid ((h+t)>>1)
#define ull unsigned ll
namespace IO{
    char ss[1<<24],*A=ss,*B=ss;
    IL char gc()
    {
        return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
    }
    template<class T> void read(T &x)
    {
        rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
        while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
    }
    char sr[1<<24],z[20]; ll Z,C1=-1;
    template<class T>void wer(T x)
    {
        if (x<0) sr[++C1]='-',x=-x;
        while (z[++Z]=x%10+48,x/=10);
        while (sr[++C1]=z[Z],--Z);
    }
    IL void wer1()
    {
        sr[++C1]=' ';
    }
    IL void wer2()
    {
        sr[++C1]='\n';
    }
    template<class T>IL void maxa(T &x,T y) {if (x<y) x=y;}
    template<class T>IL void mina(T &x,T y) {if (x>y) x=y;} 
    template<class T>IL T MAX(T x,T y){return x>y?x:y;}
    template<class T>IL T MIN(T x,T y){return x<y?x:y;}
};
using namespace IO;
const ll N=3e4;
const ll M=3e4;
ll head[N],head2[N],l,s,t;
ll dis[N],v[N],flow;
struct re{
	ll a,b;
	ll c,flow;
}e[M*2];
void arr(ll x,ll y,ll z)
{
	e[++l].a=head[x];
	e[l].b=y;
	e[l].c=z;
	head[x]=l;
}
IL void arr2(ll x,ll y,ll z)
{
	arr(x,y,z); arr(y,x,0);
}
const ll INF=1e17;
IL bool bfs()
{
	stack<ll> S;
	S.push(s);
	rep(i,s,t) dis[i]=INF; dis[s]=0;
	while (!S.empty())
	{
		ll x=S.top(); S.pop();
		for (rint u=head[x];u;u=e[u].a)
		{
			ll v=e[u].b;
			if (dis[v]==INF&&e[u].c>e[u].flow)
			{
				dis[v]=dis[x]+1; S.push(v);
			}
		}
	}
	return dis[t]!=INF;
}
IL ll dfs(ll x,ll y)
{
	if (x==t||!y) return(y);
	ll f,flow=0;
	for (rint u=head[x];u;u=e[u].a)
	{
		ll v=e[u].b;
		if (dis[v]==dis[x]+1&&(f=dfs(v,MIN(y,e[u].c-e[u].flow)))>0)
		{
			y-=f; flow+=f; e[u].flow+=f;
			if (u%2) e[u+1].flow-=f; else e[u-1].flow-=f;
		}
		head[x]=u;
		if (!y) return(flow);
	}
	return flow;
}
void maxflow()
{
	flow=0;
	mep(head2,head);
	while (bfs())
	{
		flow+=dfs(s,INF);
		mep(head,head2);
	}
}
int main()
{
	ll n,m;
	read(n); read(m);
	s=0,t=n+m+1;
	rep(i,1,n) read(v[i]),arr2(s,i,v[i]);
	ll ans=0;
	rep(i,1,m)
	{
		ll x,y,z;
	    read(x); read(y); read(z);
	    arr2(x,i+n,INF); arr2(y,i+n,INF);
	    arr2(i+n,t,z);
	    ans+=z;
	}
	maxflow();
	cout<<ans-flow<<endl;
	return 0;
}