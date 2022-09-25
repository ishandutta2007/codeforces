#include<cstdio>
#include<algorithm>
using namespace std;
#define N 50050
#define M 15050000
#define ll long long
int n,m,as[N],c1,ct=1,ch[M][2],is[M],fg[M],fa[M],t1[M],is1[M],lg2[1<<17];
ll s[N][3],tp[N*2],l,r;
char s1[10];
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
void ins(ll v,int d)
{
	int st=1;
	for(int t=n-1;t>=d;t--)
	{
		int tp=(v>>t)&1;
		if(!ch[st][tp])ch[st][tp]=++ct;
		st=ch[st][tp];
	}
}
int doit1(ll v,int d)
{
	int st=1;
	for(int t=n-1;t>=d;t--)
	{
		is1[st]=1;
		int tp=(v>>t)&1;
		st=ch[st][tp];
	}
	is[st]=is1[st]=1;return st;
}
void dfs1(int u,int x)
{
	if(!u)return;
	if(is[u])fa[finds(u)]=finds(x);
	dfs1(ch[u][0],x);dfs1(ch[u][1],x);
}
void doit2(ll v,int d,int u)
{
	int st=1;
	for(int t=n-1;t>=d;t--)
	{
		if(is[st])fa[finds(u)]=finds(st);
		int tp=(v>>t)&1;
		st=ch[st][tp];
		if(!st)return;
	}
	if(is[st])fa[finds(u)]=finds(st);
	if(is1[st])
	if(fg[st])fa[finds(fg[st])]=finds(u);
	else fg[st]=u,dfs1(st,u);
}
int query(ll x,ll y)
{
	int as=0,st;
	st=1;
	for(int t=n-1;t>=0;t--)
	{
		if(is[st])t1[finds(st)]=1;
		int tp=(x>>t)&1;
		st=ch[st][tp];
	}
	if(is[st])t1[finds(st)]=1;
	st=1;
	for(int t=n-1;t>=0;t--)
	{
		if(is[st]&&t1[finds(st)])as=1;
		int tp=(y>>t)&1;
		st=ch[st][tp];
	}
	if(is[st]&&t1[finds(st)])as=1;
	st=1;
	for(int t=n-1;t>=0;t--)
	{
		if(is[st])t1[finds(st)]=0;
		int tp=(x>>t)&1;
		st=ch[st][tp];
	}
	if(is[st])t1[finds(st)]=0;
	return as;
}
int lg(ll x)
{
	int as=0;
	if(x>=(1ll<<32))x>>=32,as+=32;
	if(x>=(1ll<<16))x>>=16,as+=16;
	return lg2[x]+as;
}
void modify0(ll l,ll r)
{
	r++;
	while(l!=r)
	{
		if((l&-l)<=(r&-r)&&l)ins(l,lg(l&-l)),l+=l&-l;
		else ins(r-(r&-r),lg(r&-r)),r-=r&-r;
	}
}
void doit3(ll v,int d)
{
	int st=doit1(v,d);
	doit2(v,d,st);
}
ll l1,r1;
int st[62],fu;
void doit4(int x,int y,ll lb,int de)
{
	ll rb=lb+(1ll<<de)-1;
	st[de]=st[de+1];
	if(is[y])st[de]=y;
	if(lb>=l1&&rb<=r1)
	{
		if(st[de])fa[finds(x)]=finds(st[de]);
		if(y&&is1[y]&&!fg[y])fg[y]=x,dfs1(y,x);
		else if(y&&is1[y]&&fg[y])fa[finds(x)]=finds(fg[y]);
		return;
	}
	int tp=fu==de;
	if(l1<lb+(1ll<<de-1))doit4(ch[x][0],ch[y][tp],lb,de-1);
	if(r1>=lb+(1ll<<de-1))doit4(ch[x][1],ch[y][!tp],lb+(1ll<<de-1),de-1);
}
void modify1(ll l,ll r)
{
	r++;
	l1=l,r1=r-1;
	while(l!=r)
	{
		if((l&-l)<=(r&-r)&&l)doit3(l,lg(l&-l)),l+=l&-l;
		else doit3(r-(r&-r),lg(r&-r)),r-=r&-r;
	}
	if(l1<=r1)for(int i=0;i<n;i++)fu=i+1,doit4(1,1,0,n);
}
int main()
{
	for(int i=2;i<1<<16;i++)lg2[i]=lg2[i>>1]+1;
	scanf("%d%d",&n,&m);
	tp[++c1]=-1,tp[++c1]=1ll<<n;
	for(int i=1;i<=m;i++)
	{
		scanf("%s%lld%lld",s1+1,&l,&r);
		s[i][1]=l,s[i][2]=r;
		if(s1[1]=='a')s[i][0]=1;
		else s[i][0]=2,tp[++c1]=l,tp[++c1]=r,modify0(l,r);
	}
	sort(tp+1,tp+c1+1);
	for(int i=1;i<=c1;i+=2)modify0(tp[i]+1,tp[i+1]-1);
	for(int i=1;i<=ct;i++)fa[i]=i;
	for(int i=1;i<=c1;i+=2)modify1(tp[i]+1,tp[i+1]-1);
	for(int i=m;i>=1;i--)
	if(s[i][0]==2)modify1(s[i][1],s[i][2]);
	else as[i]=query(s[i][1],s[i][2]);
	for(int i=1;i<=m;i++)if(s[i][0]==1)printf("%d\n",as[i]);
}