#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N 132001
#define mod 998244353
int n,ntt[N],rev[N],a,b,c[N],d[N],g[2][N*2],head[N],cnt,sz[N],tp[N],sn[N];
long long s;
vector<int> as[N],fu[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
int pw(int a,int p){int as=1;while(p){if(p&1)as=1ll*as*a%mod;a=1ll*a*a%mod;p>>=1;}return as;}
void pre()
{
	for(int i=0;i<2;i++)
	for(int j=2;j<=1<<17;j<<=1)
	{
		int st=1,w=pw(3,(mod-1)/j);
		if(i==0)w=pw(w,mod-2);
		for(int k=0;k<j>>1;k++)g[i][j+k]=st,st=1ll*st*w%mod;
	}
}
void dft(int s,int *a,int t)
{
	for(int i=0;i<s;i++)rev[i]=(rev[i>>1]>>1)|((i&1)*(s>>1)),ntt[rev[i]]=a[i];
	for(int i=2;i<=s;i<<=1)
	for(int j=0;j<s;j+=i)
	for(int k=j,st=i;k<j+(i>>1);k++,st++)
	{
		int v1=ntt[k],v2=1ll*ntt[k+(i>>1)]*g[t][st]%mod;
		ntt[k]=(v1+v2)-(v1+v2>=mod?mod:0);
		ntt[k+(i>>1)]=v1-v2+(v1<v2?mod:0);
	}
	int inv=pw(s,t==0?mod-2:0);
	for(int i=0;i<s;i++)a[i]=1ll*ntt[i]*inv%mod;
}
vector<int> polymul(vector<int> a,vector<int> b)
{
	int s1=a.size()-1,s2=b.size()-1;
	if(s1+s2<=200)
	{
		for(int i=0;i<=s1+s2;i++)c[i]=0;
		for(int i=0;i<=s1;i++)
		for(int j=0;j<=s2;j++)
		c[i+j]=(c[i+j]+1ll*a[i]*b[j])%mod;
		vector<int> f;
		for(int i=0;i<=s1+s2;i++)f.push_back(c[i]);
		return f;
	}
	int l=1;while(l<=s1+s2+1)l<<=1;
	for(int i=0;i<l;i++)c[i]=d[i]=0;
	for(int i=0;i<=s1;i++)c[i]=a[i];
	for(int i=0;i<=s2;i++)d[i]=b[i];
	dft(l,c,1);dft(l,d,1);for(int i=0;i<l;i++)c[i]=1ll*c[i]*d[i]%mod;dft(l,c,0);
	vector<int> f;
	for(int i=0;i<=s1+s2;i++)f.push_back(c[i]);
	return f;
}
vector<int> polyadd(vector<int> a,vector<int> b)
{
	int s1=a.size()-1,s2=b.size()-1;
	if(s1>s2){for(int i=0;i<=s2;i++)a[i]=(a[i]+b[i])%mod;return a;}
	else {for(int i=0;i<=s1;i++)b[i]=(b[i]+a[i])%mod;return b;}
}
struct sth{vector<int> a,b;};
sth solve(int l,int r)
{
	if(l==r){sth tp;tp.b=fu[l];tp.a.push_back(1);return tp;}
	int mid=(l+r)>>1;
	sth v1=solve(l,mid),v2=solve(mid+1,r);
	return (sth){polyadd(v2.a,polymul(v1.a,v2.b)),polymul(v1.b,v2.b)};
}
vector<int> solve1(int l,int r)
{
	if(l==r)return fu[l];
	int mid=(l+r)>>1;
	return polymul(solve1(l,mid),solve1(mid+1,r));
}
void dfs0(int u,int fa)
{
	sz[u]=1;
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs0(ed[i].t,u),sn[u]=sz[sn[u]]<sz[ed[i].t]?ed[i].t:sn[u],sz[u]+=sz[ed[i].t];
}
void dfs1(int u,int fa,int v)
{
	tp[u]=v;
	if(sn[u])dfs1(sn[u],u,v);
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa&&ed[i].t!=sn[u])dfs1(ed[i].t,u,ed[i].t);
	int ct=0;
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa&&ed[i].t!=sn[u])fu[++ct]=as[ed[i].t];
	if(ct)as[u]=solve1(1,ct);
	else as[u].push_back(1);
	int s1=as[u].size();
	as[u].push_back(0);
	for(int i=s1-1;i>=0;i--)as[u][i+1]=as[u][i];as[u][0]=0;
	if(tp[u]==u)
	{
		int ct1=1,st=u;
		while(sn[st])st=sn[st],ct1++;
		int ct2=ct1;st=u;
		while(st)fu[ct2]=as[st],ct2--,st=sn[st];
		sth fuc=solve(1,ct1);
		as[u]=polyadd(fuc.a,fuc.b);
	}
}
int main()
{
	scanf("%d%lld",&n,&s);pre();
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	dfs0(1,0);dfs1(1,0,1);
	int tp=1,as1=0;
	for(int i=1;i<=n;i++)
	{
		as1=(as1+1ll*tp*as[1][i])%mod;
		tp=1ll*tp*((s+i)%mod)%mod*pw(i,mod-2)%mod;
	}
	printf("%d\n",as1);
}