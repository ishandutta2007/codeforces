#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
cpnst ll mod=1e9+7;
int n;
struct segtree
{
	ll val[1111111],tag[1111111];
	void pushu(int p){val[p]=(val[p<<1]+val[p<<1|1])%mod;}
	void push(int p,ll d,int pl,int pr)
	{(val[p]+=(pr-pl+1)*d)%=mod,(tag[p]+=d)%=mod;}
	void pushd(int p,int pl,int pr)
	{
		if(!tag[p])return;
		int mid=(pl+pr)>>1;
		push(p<<1,tag[p],pl,mid),push(p<<1|1,tag[p],mid+1,pr),tag[p]=0;
	}ll ask(int l,int r,int p=1,int pl=1,int pr=n)
	{
		if(pl>r||l>pr)return 0;
		if(l<=pl&&pr<=r)return val[p];
		pushd(p,pl,pr);
		int mid=(pl+pr)>>1;
		return(ask(l,r,p<<1,pl,mid)+ask(l,r,p<<1|1,mid+1,pr))%mod;
	}void updata(int l,int r,ll d,int p=1,int pl=1,int pr=n)
	{
		if(pl>r||l>pr)return;
		if(l<=pl&&pr<=r)return push(p,d,pl,pr);
		pushd(p,pl,pr);
		int mid=(pl+pr)>>1;
		updata(l,r,d,p<<1,pl,mid),updata(l,r,d,p<<1|1,mid+1,pr),pushu(p);
	}
}T;
ll qpow(ll x,ll k)
{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
int ds[1111111],siz[1111111],dep[1111111];
#include<vector>
std::vector<int>v[1111111],lf[1111111],rf[1111111];
void dfs(int p=1,int f=0)
{
	siz[p]=1,dep[p]=dep[f]+1;
	for(auto t:v[p])
		if(t^f)dfs(t,p),siz[p]+=siz[t],ds[p]=(siz[ds[p]]<siz[t])?t:ds[p];
}
int top[1111111],fa[1111111],dfn[1111111],rev[1111111],ttt;
void split(int p=1,int f=0,int tp=1)
{
	top[p]=tp,fa[p]=f,dfn[p]=++ttt;
	if(ds[p])split(ds[p],p,tp);
	for(auto t:v[p])if(t^f)if(t^ds[p])split(t,p,t);
}
ll ask(int x)
{
	ll ret=0;
	for(;x;x=fa[top[x]])ret+=T.ask(dfn[top[x]],dfn[x]);
	return ret%mod;
}
void modify(int x,int d)
{for(;x;x=fa[top[x]])T.updata(dfn[top[x]],dfn[x],d);}
ll p[1111111],all,ap,tp;
void ins(int x)
{
	all+=ap*p[x]%mod*dep[x]+tp*p[x],(ap+=p[x])%=mod,(tp+=p[x]*dep[x])%=mod,
	all-=(ask(x)<<1)*p[x],modify(x,p[x]),all=(all%mod+mod)%mod;
}
void rem(int x)
{
	modify(x,-p[x]),
	all+=(ask(x)<<1)*p[x],
	(ap-=p[x])%=mod,
	(tp-=p[x]*dep[x])%=mod,all-=ap*p[x]%mod*dep[x]+tp*p[x],all=(all%mod+mod)%mod;
}
int main()
{
	scanf("%d",&n);
	register int i;
	ll t=1;
	int l,r;
	for(i=1;i<=n;i++)
		scanf("%d%d",&l,&r),t=t*(r-l+1)%mod,
		p[i]=qpow(r-l+1,mod-2),lf[l].push_back(i),rf[r+1].push_back(i);
	for(i=1;i<n;i++)
		scanf("%d%d",&l,&r),v[l].push_back(r),v[r].push_back(l);
	dfs(),split();
	ll ans=0;
	for(i=1;i<=1e5;i++)
	{
		for(auto x:lf[i])ins(x);
		for(auto y:rf[i])rem(y);
		ans+=all;
	}printf("%lld\n",ans%mod*t%mod);
}
/*
Just go for it.
*/