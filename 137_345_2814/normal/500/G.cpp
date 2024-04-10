#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200500
#define ll long long
int n,q,a,b,v[4],head[N],cnt,dep[N],f[N][18];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs(int u,int fa){dep[u]=dep[fa]+1;f[u][0]=fa;for(int i=1;i<=17;i++)f[u][i]=f[f[u][i-1]][i-1];for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
int LCA(int x,int y){if(dep[x]<dep[y])swap(x,y);for(int i=17;i>=0;i--)if(dep[x]-dep[y]>=(1<<i))x=f[x][i];if(x==y)return x;for(int i=17;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];return f[x][0];}
int doit(int x,int y){return dep[x]>dep[y]?x:y;}
int getdis(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
bool chk(int x,int y,int a){return getdis(x,a)+getdis(y,a)==getdis(x,y);}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b){x=1,y=0;return a;}
	ll g=exgcd(b,a%b,y,x);y-=a/b*x;return g;
}
ll excrt(ll b,ll a,ll d,ll c)
{
	ll x,y;
	ll g=exgcd(b,d,x,y),l=b/g*d;
	if((a-c)%g)return 1e18;
	ll as=a,tp=(c-a%d+d)%d/g;
	as=(as+tp*b%l*x)%l;as=(as+l)%l;
	return as;
}
ll doit(ll x,ll y,ll a,ll b)
{
	x%=y;
	if(a<0){ll tp=(-a)/y;tp=(tp+1)*y;a+=tp;b+=tp;}
	ll tp=a/y*y;a-=tp;b-=tp;
	if(b>=y)return 0;
	if(!x)return -1;
	if(b/x>(a-1)/x)return (a-1)/x+1;
	ll ry=doit(y,x,-b,-a);
	if(ry==-1)return -1;
	return (b+ry*y)/x;
}
ll solve(int l1,int r1,int l2,int r2,int sl,int ty)
{
//	printf("%d %d %d %d %d %d\n",l1,r1,l2,r2,sl,ty);
	ll as=1e18,s1=l1+r1+sl,s2=l2+r2+sl;
	for(int f=0;f<2;f++)
	{
		int lb,rb;
		if(!f)lb=l1,rb=ty?r2+sl-1:l2;
		else lb=sl+l1-1,rb=ty?r2:l2+sl-1;
		for(int p=-1;p<2;p+=2)
		for(int q=-1;q<2;q+=2)
		as=min(as,excrt(s1*2-2,s1*2-2+p*lb,s2*2-2,s2*2-2+q*rb));
	}
	ll cr1=s1*2-2,cr2=s2*2-2;
	//case 1: t mod cr1 + t mod cr2 = s2*2+l1-l2,t mod cr1 in [l1,l1+sl)
	//t=cr1*k1+r1=cr2*k2+(s2*2+l1-l2)-r1
	//cr1*k1-cr2*k2\in((s2*2+l1-l2)-2*(l1+sl),(s2*2+l1-l2)-2*l1]
	//if ty,vl=sl+l1+r2
	ll lb=l1,rb=l1+sl-1,vl=s2*2+l1-l2-2,as1;
	if(ty)vl=sl+l1+r2-1;
	as1=doit(cr1,cr2,vl-2*rb,vl-2*lb);
	if(vl&1)as1=-1;
	if(as1!=-1)
	{
		ll k1=as1,k2=(k1*cr1-(vl-2*rb))/cr2;
		ll r1=(cr2*k2-cr1*k1+vl)/2;
		as=min(as,k1*cr1+r1);
	}
	//case 2: t mod cr1 + t mod cr2 = s1*2+l2-l1,t mod cr1 in (s1*2-l1-sl,s1*2-l1]
	lb=s1*2-l1-sl-1,rb=s1*2-l1-2,vl=s1*2+l2-l1-2;
	if(ty)vl=s1+s2+sl+l2+r1-3;
	as1=doit(cr1,cr2,vl-2*rb,vl-2*lb);
	if(vl&1)as1=-1;
	if(as1!=-1)
	{
		ll k1=as1,k2=(k1*cr1-(vl-2*rb))/cr2;
		ll r1=(cr2*k2-cr1*k1+vl)/2;
		as=min(as,k1*cr1+r1);
	}
	if(as>1e16)as=-1;
	return as;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	dfs(1,0);
	scanf("%d",&q);
	while(q--)
	{
		for(int i=0;i<4;i++)scanf("%d",&v[i]);
		int as=0;
		for(int i=0;i<4;i++)for(int j=i+1;j<4;j++)as=doit(as,LCA(v[i],v[j]));
		if(!chk(v[0],v[1],as)||!chk(v[2],v[3],as)){printf("-1\n");continue;}
		int s1=as,s2=as,ds=0;
		for(int i=0;i<4;i++)for(int j=i+1;j<4;j++)
		{
			int l=LCA(v[i],v[j]);
			if(!chk(v[0],v[1],l)||!chk(v[2],v[3],l))continue;
			int d1=getdis(l,s1);
			if(d1>ds)ds=d1,s2=l;
		}
		if(getdis(v[0],s1)>getdis(v[0],s2))swap(s1,s2);
//		printf("%d %d\n",s1,s2);
		int l1=getdis(v[0],s1),r1=getdis(v[1],s2),l2=getdis(v[2],s1),r2=getdis(v[3],s2),sl=getdis(s1,s2),fg=0;
		if(l2+r2>getdis(v[2],v[3]))l2-=sl,r2-=sl,fg=1,swap(l2,r2);
		printf("%lld\n",solve(l1,r1,l2,r2,sl+1,fg));
	}
}