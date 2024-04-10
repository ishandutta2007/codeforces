#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db long double
#define pii pair<ll,ll>
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
	ll x=0;char c=gc();while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-48,c=gc();return x;
}
const int N=100005,M=400005,P=1e9+7;
int n,m,cc,tt,sz,hd[N],vis[N],o[N];ll ans,d[N],b[60];
struct E{int v,nxt;ll w;}e[M];
inline void add(int u,int v,ll w){e[++cc]=(E){v,hd[u],w};hd[u]=cc;}
inline void ins(ll x){per(i,59,0)if(x>>i&1){if(!b[i]){b[i]=x;sz++;break;}else x^=b[i];}}
void dfs(int x,ll w)
{
	vis[x]=1;d[x]=w;o[++tt]=x;
	for(int i=hd[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(vis[y])ins(d[y]^w^e[i].w);else dfs(y,w^e[i].w);
	}
}
int main()
{
	n=rd();m=rd();rep(i,1,m){int u=rd(),v=rd();ll w=rd();add(u,v,w);add(v,u,w);}
	rep(i,1,n)if(!vis[i])
	{
		tt=0;sz=0;memset(b,0,sizeof(b));dfs(i,0);
		rep0(j,0,60)
		{
			int c=(1ll<<j)%P,ff=0;rep0(k,0,60)if(b[k]>>j&1)ff=1;
			if(ff){ans=(ans+1ll*tt*(tt-1)/2%P*((1ll<<sz-1)%P)%P*c)%P;continue;}
			int s=0;rep(i,1,tt)if(d[o[i]]>>j&1)s++;
			ans=(ans+1ll*s*(tt-s)%P*((1ll<<sz)%P)%P*c)%P;
		}
	}
	printf("%d\n",ans%P);return 0;
}