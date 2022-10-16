//csp[2019].rp++,
//csp[2019].score++;
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
ll x,y;
const int maxn=33333333;
bool flag[maxn+100];
int prm[2222222],top;
void primer()
{
	register int i,ii;
	for(i=2;i<=maxn;i++)
		if(!flag[i])
		{
			prm[++top]=i;
			for(ii=i;ii<=maxn/i;ii++)
				flag[i*ii]=1;
		}
}
inline void exgcd(ll a,ll b)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b);
	ll t=x;x=y,y=t-(a/b)*y;
}
struct pii
{ll x,k;int Id;};
inline bool operator<(const pii x,const pii y)
{return x.k<y.k;}
ll pr[11111];
int tpr;
inline bool split(ll x)
{
	tpr=0;
	for(register int i=1;i<=top;i++)
		if(x%prm[i]==0)
		{
			pr[++tpr]=prm[i];
			while(x%prm[i]==0)x/=prm[i];
		}
	if(x>1)pr[++tpr]=x;
	return tpr;
}
pii arg[11111];
bool ans[11111];
ll lst=-1;
struct edg
{int p,t,l;}e[2222222];
int h[111111],tot;
inline void build(int x,int y,int l)
{e[++tot]=(edg){h[x],y,l},h[x]=tot;}
ll dis[111111];
bool vis[111111];
struct piii
{int x;ll v;};
inline bool operator<(const piii x,const piii y)
{return x.v>y.v;}
#include<queue>
std::priority_queue<piii>q;
void dij(int S)
{
	register int i;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	q.push((piii){S,0});
	while(q.size())
	{
		int p=q.top().x;q.pop();
		if(vis[p])continue;
		vis[p]=1;
		for(i=h[p];i;i=e[i].p)
		{
			int to=e[i].t;
			if(dis[to]>dis[p]+e[i].l)
				dis[to]=dis[p]+e[i].l,q.push((piii){to,dis[to]});
		}
	}
}
inline ll mul(ll x,ll y,ll p)
{ll s=0;for(;y;y>>=1,(x+=x)%=p)if(y&1)(s+=x)%=p;return s;}
void query(ll k,ll n,int Id)
{
	ll g;
	if(k==1){ans[Id]=0;return;}
	if(lst^k)split(k);
	if(tpr==1)ans[Id]=(n%pr[1]==0);
	else if(tpr==2)
	{
		exgcd(pr[1],pr[2]),g=(x%pr[2]+pr[2])%pr[2],g=mul(g,n,pr[2]);
		if(g>n/pr[1])ans[Id]=0;
		else ans[Id]=1;
	}else
	{
		memset(h,0,sizeof(h)),tot=0;
		if(lst^k)
		{
			register int i,ii;
			for(i=0;i<pr[1];i++)
				for(ii=2;ii<=tpr;ii++)
					build(i,(i+pr[ii])%pr[1],pr[ii]);
			dij(0);
		}ans[Id]=dis[n%pr[1]]<=n;
	}lst=k;
}
int qq;
int main()
{
	scanf("%d",&qq);
	primer();
	register int i;
	for(i=1;i<=qq;i++)
		scanf("%lld%lld",&arg[i].x,&arg[i].k),arg[i].Id=i;
	std::sort(arg+1,arg+qq+1);
	for(i=1;i<=qq;i++)query(arg[i].k,arg[i].x,arg[i].Id);
	for(i=1;i<=qq;i++)puts(ans[i]?"YES":"NO");
}