#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
typedef double db;
struct pii
{int x,y;
pii(int xx=0,int yy=0){x=xx,y=yy;}};
inline bool operator<(const pii x,cpnst pii y)
{return x.x<y.x;}
ll a[1111111],b[1111111];
char str[1111111];
struct segt
{int l,r;ll mx,tag;}tr[4444444];
inline void push(int p,ll d)
{tr[p].mx+=d,tr[p].tag+=d;}
inline void pushd(int p)
{push(p<<1,tr[p].tag),push(p<<1|1,tr[p].tag),tr[p].tag=0;}
inline ll max(ll x,ll y)
{return(x>y)?x:y;}
inline void pushu(int p)
{tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);}
void build(int l=1,int r=1e6,int p=1)
{
	tr[p].l=l,tr[p].r=r;
	if(l==r){tr[p].mx=-b[l];return;}
	int mid=(l+r)>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1),pushu(p);
}
void modify(int l,int r,ll d,int p=1)
{
	if(l>r)return;
	if(tr[p].l>r||l>tr[p].r)return;
	if(l<=tr[p].l&&tr[p].r<=r)return push(p,d);
	pushd(p),modify(l,r,d,p<<1),
	modify(l,r,d,p<<1|1),pushu(p);
}
#include<vector>
std::vector<int>v[1111111],w[1111111];
int n,m,p;
void exec()
{
	scanf("%d%d%d",&n,&m,&p);
	register int i,ii;
	for(i=1;i<=1e6;i++)a[i]=1e18,b[i]=1e18;
	for(i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(a[x]>y)a[x]=y;
	}for(i=1e6-1;i;i--)
		if(a[i]>a[i+1])a[i]=a[i+1];
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(b[x]>y)b[x]=y;
	}for(i=1e6-1;i;i--)
		if(b[i]>b[i+1])b[i]=b[i+1];
	ll ans=-1e18;
	for(i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x+1].push_back(y+1),w[x+1].push_back(z);
	}build();
	for(i=1;i<=1e6;i++)
	{
		for(ii=0;ii<v[i].size();ii++)
			modify(v[i][ii],1e6,w[i][ii]);
		//printf("%lld %lld\n",tr[1].mx,a[i]);
		if(ans<tr[1].mx-a[i])ans=tr[1].mx-a[i];
	}printf("%I64d\n",ans);
}
int main()
{
	int T=1;
//	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/