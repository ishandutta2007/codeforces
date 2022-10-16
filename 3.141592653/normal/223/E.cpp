#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,m;
#include<vector>
#include<algorithm>
typedef long long ll;
std::vector<int>v[111111],s[111111];
int siz[111111];
int fa[111111];
void dfs(int p=1,int f=0)
{fa[p]=f,siz[p]=1;for(auto t:v[p])if(!siz[t])dfs(t,p),siz[p]+=siz[t];}
struct pnt
{ll x,y;}p[111111];
ll operator*(pnt x,pnt y){return x.x*y.y-x.y*y.x;}
pnt operator-(pnt x,pnt y){x.x-=y.x,x.y-=y.y;return x;}
pnt Cntr;
bool operator<(pnt x,pnt y)
{
	x=x-Cntr,y=y-Cntr;
	if(x.x==y.x&&x.y==y.y)return 0;
	if(x.x>=0&&x.y>=0){if(y.x<0||y.y<0)return 1;}
	else if(y.x>=0&&y.y>=0)return 0;
	if(x.x<0&&x.y>=0){if(y.x>=0||y.y<0)return 1;}
	else if(y.x<0&&y.y>=0)return 0;
	if(x.x<0&&x.y<0){if(y.x>=0||y.y>=0)return 1;}
	else if(y.x<0&&y.y<0)return 0;
	return x*y>0;
}
bool comp(int x,int y){return p[x]<p[y];}
int q[1111111];
#include<map>
std::map<ll,int>mp;
#define Rf(x,y) ((x)*(1ll<<30)+(y))
void adjust(int k)
{
	register int i;
	pnt ps=pnt{0,0};
	ll S=0;
	for(i=1;i<=k;i++)S+=(p[q[i-1]]-ps)*(p[q[i]]-p[q[i-1]]);
	if(S<0)for(i=1;i<=(k>>1);i++){int tp=q[i];q[i]=q[k-i+1],q[k-i+1]=tp;}
}
bool incl(int l,int d,int r)
{
	int Lt=mp[Rf(d,r)],Dg=mp[Rf(d,fa[d])],Rt=mp[Rf(d,l)];
	return(Lt<=Dg&&Dg<=Rt)||(Lt>Rt&&(Dg>=Lt||Dg<=Rt));
}
int except(int l,int d,int r)
{
	int Lt=mp[Rf(d,l)],Rt=mp[Rf(d,r)];
	if(Lt<=Rt)retrun s[d][Rt-1]-s[d][Lt];
	int ret=s[d].back()-s[d][Lt];
	if(Rt)ret+=s[d][Rt-1];
	return ret;
}
void solve()
{
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		int S=0,r=0;
		for(auto t:v[i])mp[Rf(i,t)]=r++,S+=siz[t]*(fa[t]==i),s[i].push_back(S);
	}int Q;
	scanf("%d",&Q);
	for(i=1;i<=Q;i++)
	{
		int k;
		scanf("%d",&k);
		for(ii=1;ii<=k;ii++)scanf("%d",q+ii);
		q[0]=q[k],q[k+1]=q[1],adjust(k),q[0]=q[k],q[k+1]=q[1];
		ll ans=0;
		for(ii=1;ii<=k;ii++)
		{
			if(q[ii]==1)ans+=n;
			else if(!incl(q[ii-1],q[ii],q[ii+1]))ans+=siz[q[ii]];
			ans-=except(q[ii-1],q[ii],q[ii+1]);
		}if(ans<=0)ans+=n;
		printf("%lld\n",ans);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	int x,y;
	for(i=1;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(i=1;i<=n;i++)scanf("%lld%lld",&p[i].x,&p[i].y);
	for(i=1;i<=n;i++)Cntr=p[i],std::sort(v[i].begin(),v[i].end(),comp);
	dfs(),solve();
}
/*
Please don't let me down.
*/