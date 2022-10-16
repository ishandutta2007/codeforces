//csp[2019].rp++,
//csp[2019].score++;
#include<cstdio>
typedef unsigned long long ull;
const ull bas=1315413271;
const int rgg=131071;
ull k[555555];
int h[111111],tot;
struct edg
{int p,t,l;}e[222222];
inline void build(int x,int y,int l)
{e[++tot]=(edg){h[x],y,l},h[x]=tot;}
int frm[111111],tra[111111],dis[111111];
bool vis[111111];
struct segt
{
	int l,r,sum;
	ull h;
	segt*s[2];
	segt(int lg=0,int rg=0)
	{l=lg,r=rg,h=sum=0,s[0]=s[1]=0;}
	void update()
	{
		int siz=(r-l+1)>>1;
		h=s[0]->h+s[1]->h*k[siz];
		sum=s[0]->sum+s[1]->sum;
	}
}*root[555555];int rttop;
inline void pre(int l=0,int r=rgg,segt*p=root[0])
{
	if(l==r)return;
	int mid=(l+r)>>1;
	p->s[0]=new segt(l,mid),p->s[1]=new segt(mid+1,r);
	pre(l,mid,p->s[0]),pre(mid+1,r,p->s[1]);
}
#include<queue>
struct pii
{int x,v;pii(int xx=0,int vv=0){x=xx,v=vv;}};
inline bool operator<(const pii x,const pii y)
{
	segt*tx=root[x.v],*ty=root[y.v];
	if(tx->h==ty->h)return 0;
	while(tx->l^tx->r)
	{
		if(tx->s[1]->h^ty->s[1]->h)tx=tx->s[1],ty=ty->s[1];
		else tx=tx->s[0],ty=ty->s[0];
	}return tx->sum;
}
inline bool comp(segt*tx,segt*ty)
{
	if(tx->h==ty->h)return 0;
	while(tx->l^tx->r)
	{
		if(tx->s[1]->h^ty->s[1]->h)tx=tx->s[1],ty=ty->s[1];
		else tx=tx->s[0],ty=ty->s[0];
	}return tx->sum;
}
std::priority_queue<pii>q;
inline void fill(int l,int r,segt*f,segt*p,segt*nul=root[0])
{
	if(p->l>r||l>p->r){*p=*f;return;}
	if(p->l>=l&&p->r<=r){*p=*nul;return;}
	int mid=(p->l+p->r)>>1;
	p->s[0]=new segt(p->l,mid),p->s[1]=new segt(mid+1,p->r);
	fill(l,r,f->s[0],p->s[0],nul->s[0]),
	fill(l,r,f->s[1],p->s[1],nul->s[1]);
	p->update();
}
inline bool valid(segt*p)
{
	if(p->l==p->r)return 1;
	if(valid(p->s[0])&&valid(p->s[1]))
	{
		if(p->sum==p->s[0]->sum+p->s[1]->sum)
			return 1;
		else return 0;
	}return 0;
}
inline int FindKth0Bit(int k,segt*p)
{
	if(p->l==p->r)return p->l;
	int nowsiz=(p->r-p->l+1)>>1;
	if(k>nowsiz-p->s[0]->sum)
		return FindKth0Bit(k-nowsiz+p->s[0]->sum,p->s[1]);
	return FindKth0Bit(k,p->s[0]);
}
inline int sumit(int x,segt*p)
{
	if(p->r<=x)return p->sum;
	if(p->l>x)return 0;
	return sumit(x,p->s[0])+sumit(x,p->s[1]);
}
inline void writeln(int x,segt*f,segt*r2)
{
	r2->s[0]=f->s[0],r2->s[1]=f->s[1];
	int l=f->l,r=f->r,mid=(l+r)>>1;
	if(l==r){r2->sum=1,r2->h=1;return;}
	if(x<=mid)r2->s[0]=new segt(l,mid),writeln(x,f->s[0],r2->s[0]);
	else r2->s[1]=new segt(mid+1,r),writeln(x,f->s[1],r2->s[1]);
	r2->update();
}
inline void callforbit(segt*x,int l=100,int r=0)
{
	register int i;
	for(i=l;i>=r;i--)
		if(i)printf("%d",sumit(i,x)-sumit(i-1,x));
		else printf("%d",sumit(i,x));
	puts("");
}
inline int modify(int x,segt*r1,segt*r2)
{
	r2->s[0]=r1->s[0],r2->s[1]=r1->s[1];
	int l=r2->l,r=r2->r,mid=(l+r)>>1;
	int ret=0;
	if(l==r)
		return r2->sum=1,r2->h=1,(!r1->sum);
	if(x<=mid)r2->s[0]=new segt(l,mid),ret=modify(x,r1->s[0],r2->s[0]);
	else r2->s[1]=new segt(mid+1,r),ret=modify(x,r1->s[1],r2->s[1]);
	r2->update();
	return ret;
}
inline int addval(int x,segt*pre)
{
	rttop++;
	if(!modify(x,pre,root[rttop]))
	{
		int k=x+2-sumit(x,pre);
		int xx=FindKth0Bit(k,pre);
		rttop++,writeln(xx,root[rttop-1],root[rttop]),
		rttop++,fill(x,xx-1,root[rttop-1],root[rttop]);
	}return rttop;
}
void dij(int S)
{
	dis[S]=0,frm[S]=-1;
	q.push(pii(S,0));
	while(q.size())
	{
		pii pp=q.top();q.pop();
		int p=pp.x;
		if(vis[p])continue;
		vis[p]=1;
		for(register int i=h[p];i;i=e[i].p)
		{
			int to=e[i].t;
			if(vis[to])continue;
			int now=addval(e[i].l,root[dis[p]]);
			if((!dis[to])||(comp(root[dis[to]],root[now])))
				dis[to]=now,frm[to]=p,tra[to]=e[i].l,q.push(pii(to,dis[to]));
		}
	}
}
int n,m;
typedef long long ll;
const ll mod=1e9+7;
inline ll qpow(ll x,ll k)
{ll r=1;for(;k;k>>=1,(x*=x)%=mod)if(k&1)(r*=x)%=mod;return r;}
int stk[111111],top;
int main()
{
	register int i;
	for(i=0;i<=500000;i++)
		root[i]=new segt(0,rgg);
	k[0]=1;
	for(i=1;i<=120000;i++)
		k[i]=k[i-1]*bas;
	pre();
	scanf("%d%d",&n,&m);
	int x,y,l;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&x,&y,&l),build(x,y,l),build(y,x,l);
	int s,t;
	scanf("%d%d",&s,&t),dij(s);
	int p=t;
	if(!frm[t])return puts("-1"),0;
	ll ans=0;
	for(;p!=s;p=frm[p])
		stk[++top]=p,ans+=qpow(2,tra[p]);
	stk[++top]=s;
	printf("%lld\n",ans%mod);
	printf("%d\n",top);
	for(;top;top--)
		printf("%d%c",stk[top],(top^1)?' ':'\n');
}