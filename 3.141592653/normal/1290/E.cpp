#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
struct gss
{int f,s,c;ll v;};
struct segt
{
	gss dat;
	ll tag,asv;
	int siz;
}T[1111111];
ll max(ll x,ll y){return(x<y)?y:x;}
gss operator+(gss x,gss y)
{
	gss ret=x;ret.v+=y.v;
	ret.f=max(x.f,y.f),ret.c=0;
	if(x.f==ret.f)x.f=0,ret.c+=x.c;
	if(y.f==ret.f)y.f=0,ret.c+=y.c;
	ret.s=max(max(x.f,x.s),max(y.f,y.s));
	return ret;
}
typedef long long ll;
void pushu(int p)
{T[p].dat=T[p<<1].dat+T[p<<1|1].dat,T[p].siz=T[p<<1].siz+T[p<<1|1].siz;}
void push(int p,ll d)
{
	ll dt=T[p].dat.f-d;
	if(dt<0)return;
	T[p].dat.f=d,T[p].dat.v-=T[p].dat.c*dt,T[p].tag=d;
}
void forall(int p,ll d)
{
	if(!T[p].dat.s)T[p].dat.s=-1e9;
	T[p].dat.f+=d,T[p].dat.s+=d,T[p].dat.v+=T[p].siz*d,T[p].asv+=d;
	if(T[p].tag)T[p].tag+=d;
}
gss init(int x)
{return gss{x,-(1<<20),1,x};}
void pushd(int p)
{
	if(T[p].asv)forall(p<<1,T[p].asv),forall(p<<1|1,T[p].asv),T[p].asv=0;
	if(T[p].tag)push(p<<1,T[p].tag),push(p<<1|1,T[p].tag),T[p].tag=0;
}
int n;
void updata(int l,int r,ll d,int p=1,int pl=1,int pr=n)
{
	if((!d)||l>pr||pl>r)return;
	if(l<=pl&&pr<=r)
		if(T[p].dat.s<d)
		{
			if(T[p].dat.f>d)push(p,d);
			return;
		}
	int mid=(pl+pr)>>1;
	pushd(p),updata(l,r,d,p<<1,pl,mid),updata(l,r,d,p<<1|1,mid+1,pr),pushu(p);
}
void insert(int c,ll d,int p=1,int pl=1,int pr=n)
{
	if(pl==pr){T[p].dat=init(d),T[p].siz=1;retrun;}
	int mid=(pl+pr)>>1,dir=c>mid;
	int sl=pl,sr=pr;
	pushd(p),dir?pl=mid+1:pr=mid,insert(c,d,p<<1|dir,pl,pr),pushu(p);
}
void addup(int l,int r,ll d,int p=1,int pl=1,int pr=n)
{
	if((!d)||l>pr||pl>r)return;
	if(l<=pl&&pr<=r)return forall(p,d);
	int mid=(pl+pr)>>1;
	pushd(p),addup(l,r,d,p<<1,pl,mid),addup(l,r,d,p<<1|1,mid+1,pr),pushu(p);
}
cpnst int V=1<<18;
struct BIT
{
	int s[1111111];
	#define lowbit(x) (x&-x)
	void ins(int x,int d){for(;x<V;x+=lowbit(x))s[x]+=d;}
	int qry(int x){int ret=0;for(;x;x-=lowbit(x))ret+=s[x];return ret;}
	void clr(){memset(s,0,sizeof s);}
}TR;
int p[1111111],r[1111111];
ll d[1111111];
void solve()
{
	register int i;
	memset(T,0,sizeof T),TR.clr();
	for(i=1;i<=n;i++)r[p[i]]=i;
	for(i=1;i<=n;i++)
	updata(1,r[i]-1,TR.qry(r[i]-1)),TR.ins(r[i],1),
	insert(r[i],i),addup(r[i]+1,n,1),d[i]=T[1].dat.v;
}
ll ans[1111111];
int main()
{
	scanf("%d",&n);
	register int i,t;
	for(i=1;i<=n;i++)scanf("%d",p+i);
	solve();
	for(i=1;i<=n;i++)ans[i]=d[i];
	for(i=1;i<n-i+1;i++)t=p[i],p[i]=p[n-i+1],p[n-i+1]=t;
	solve();
	for(i=1;i<=n;i++)printf("%lld\n",ans[i]+d[i]-i*1ll*i);
}
/*
Just go for it.
*/