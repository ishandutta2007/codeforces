#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define N 400500
int T,n,m,s[N][3],a,b,c;
vector<int> ls[N];
//kruskal tree
int ct,vl[N],ch[N][2],f1[N],id[N],fr[N][19],ci,st[N],dep[N],rid[N],se[N],re[N],c2;
int finds1(int x){return f1[x]==x?x:f1[x]=finds1(f1[x]);}
bool cmp(int a,int b){return s[a][2]<s[b][2];}
void dfs1(int u,int f)
{
	id[u]=++ci;dep[u]=dep[f]+1;rid[id[u]]=u;
	if(u<=n){se[++c2]=u;re[u]=c2;return;}
	dfs1(ch[u][0],u);dfs1(ch[u][1],u);
}
void init_k()
{
	for(int i=1;i<=n*2;i++)vl[i]=ch[i][0]=ch[i][1]=0;
	for(int i=1;i<=n;i++)f1[i]=i;
	for(int i=1;i<=m;i++)st[i]=i;
	sort(st+1,st+m+1,cmp);
	ct=n;
	for(int i=1;i<=m;i++)
	{
		int f=s[st[i]][0],t=s[st[i]][1],v=s[st[i]][2];
		f=finds1(f);t=finds1(t);
		if(f==t)continue;
		ct++;
		ch[ct][0]=f;ch[ct][1]=t;fr[f][0]=fr[t][0]=ct;
		f1[f]=f1[t]=f1[ct]=ct;vl[ct]=v;
	}
	ci=c2=0;dfs1(ct,0);
	for(int j=1;j<=18;j++)for(int i=1;i<=ct;i++)fr[i][j]=fr[fr[i][j-1]][j-1];
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int tp=dep[x]-dep[y];
	for(int i=18;i>=0;i--)if((tp>>i)&1)x=fr[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(fr[x][i]!=fr[y][i])x=fr[x][i],y=fr[y][i];
	return fr[x][0];
}
//B... algo
int getval1(int x,int y){return vl[LCA(x,y)];}
int sti[N][18],lg[N];
void init_st()
{
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;i++)sti[i][0]=getval1(se[i],se[i+1]);
	for(int j=1;j<=17;j++)for(int i=1;i+(1<<j)-1<=n;i++)sti[i][j]=max(sti[i][j-1],sti[i+(1<<j-1)][j-1]);
}
int getval(int x,int y)
{
	x=re[x];y=re[y];
	if(x>y)swap(x,y);y--;
	int tp=lg[y-x+1];
	return max(sti[x][tp],sti[y-(1<<tp)+1][tp]);
}
int cl[N],mn[N],rs[N],mn2[N],rs2[N],is[N];
int ct1,sl[N][3];
int finds(int x){return cl[x]==x?x:cl[x]=finds(cl[x]);}
int li[N][2],ri[N][2];
int getls(int x,int c){x=re[x];return li[x-1][cl[li[x-1][0]]==c];}
int getrs(int x,int c){x=re[x];return ri[x+1][cl[ri[x+1][0]]==c];}
void solve()
{
	for(int i=1;i<=n;i++)mn[i]=1e9;
	for(int i=0;i<=n+1;i++)for(int j=0;j<2;j++)li[i][j]=ri[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		li[i][0]=li[i-1][0];li[i][1]=li[i-1][1];
		if(cl[se[i]]==cl[li[i][0]])li[i][0]=se[i];
		else li[i][1]=li[i][0],li[i][0]=se[i];
	}
	for(int i=n;i>=1;i--)
	{
		ri[i][0]=ri[i+1][0];ri[i][1]=ri[i+1][1];
		if(cl[se[i]]==cl[ri[i][0]])ri[i][0]=se[i];
		else ri[i][1]=ri[i][0],ri[i][0]=se[i];
	}
	for(int i=1;i<=n;i++)
	{
		int u=i;
		for(int j=0;j<ls[i].size();j++)is[ls[i][j]]=1;
		int lb=getls(i,cl[i]);while(is[lb])lb=getls(lb,cl[i]);
		int rb=getrs(i,cl[i]);while(is[rb])rb=getrs(rb,cl[i]);
		if(lb)
		{
			int nw=lb,vl=getval(u,nw);
			if(vl<mn[u])mn[u]=vl,rs[u]=nw;
		}
		if(rb)
		{
			int nw=rb,vl=getval(u,nw);
			if(vl<mn[u])mn[u]=vl,rs[u]=nw;
		}
		for(int j=0;j<ls[i].size();j++)is[ls[i][j]]=0;
	}
}
void solve_b()
{
	for(int i=1;i<=n;i++)cl[i]=i;ct1=0;
	while(ct1<n-1)
	{
		for(int i=1;i<=n;i++)mn2[i]=1e9,cl[i]=finds(cl[i]);
		solve();
		for(int i=1;i<=n;i++)if(mn[i]<mn2[cl[i]])mn2[cl[i]]=mn[i],rs2[cl[i]]=i;
		for(int i=1;i<=n;i++)if(cl[i]==i)
		{
			int u=rs2[i],v=rs[u],vl=getval(u,v);
			if(finds(u)!=finds(v))sl[++ct1][0]=u,sl[ct1][1]=v,sl[ct1][2]=vl,cl[finds(u)]=v;
		}
	}
}
//calc ans
int head[N],cnt,f[N][18],di[N],sv[N][18],as[N];
struct edge{int t,next,v;}ed[N*2];
void adde(int f,int t,int v)
{
	ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;
	ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;
}
void dfs(int u,int fa)
{
	di[u]=di[fa]+1;
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);
	else f[u][0]=ed[i].t,sv[u][0]=ed[i].v;
}
int calc(int x,int y)
{
	int as=0;
	if(di[x]<di[y])swap(x,y);
	int tp=di[x]-di[y];
	for(int i=17;i>=0;i--)if((tp>>i)&1)as=max(as,sv[x][i]),x=f[x][i];
	if(x==y)return as;
	for(int i=17;i>=0;i--)if(f[x][i]!=f[y][i])as=max(as,max(sv[x][i],sv[y][i])),x=f[x][i],y=f[y][i];
	as=max(as,max(sv[x][0],sv[y][0]));
	return as;
}
void solve_all()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)ls[i].clear();
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		s[i][0]=a;s[i][1]=b;s[i][2]=c;
		ls[a].push_back(b);ls[b].push_back(a);
	}
	init_k();
	init_st();
	solve_b();
	for(int i=1;i<=n;i++)head[i]=0;cnt=0;
	for(int i=1;i<n;i++)adde(sl[i][0],sl[i][1],sl[i][2]);
	dfs(1,0);
	for(int j=1;j<=17;j++)for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1],sv[i][j]=max(sv[i][j-1],sv[f[i][j-1]][j-1]);
	for(int i=1;i<=m;i++)as[i]=calc(s[i][0],s[i][1]);
	for(int i=1;i<=m;i++)printf("%d ",as[i]);
	printf("\n");
}
int main()
{
	scanf("%d",&T);
	while(T--)solve_all();
}