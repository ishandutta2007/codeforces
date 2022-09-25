#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 200050
int head[N],cnt,dep[N],tp[N],id[N],sz[N],son[N],n,m,a,b,c,d,ct,f[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs1(int u,int fa){sz[u]=1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa){dfs1(ed[i].t,u);sz[u]+=sz[ed[i].t];if(sz[ed[i].t]>sz[son[u]])son[u]=ed[i].t;}}
void dfs2(int u,int v,int fa){f[u]=fa;tp[u]=v;dep[u]=dep[fa]+1;if(u==v)id[u]=++ct;if(son[u])dfs2(son[u],v,u);for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa&&ed[i].t!=son[u])dfs2(ed[i].t,ed[i].t,u);}
struct sth{double f,t;int s,v;};
vector<sth> v[N];
struct sth2{double t;int s,v,id,r;friend bool operator <(sth2 a,sth2 b){return a.t<b.t;}};
vector<sth2> tp1;
void solve(int l,int r,double s,int v1)
{
	int s1=l,s2=r;
	while(tp[s1]!=tp[s2])
	{
		if(dep[tp[s1]]<dep[tp[s2]])s1^=s2^=s1^=s2;
		s1=f[tp[s1]];
	}
	int le=dep[l]+dep[r]-min(dep[s1],dep[s2])*2;
	double st=s,et=s+1.0*le/v1;
	int fg=0;
	while(tp[l]!=tp[r])
	{
		if(dep[tp[l]]<dep[tp[r]])l^=r^=l^=r,fg^=1;
		int s3=id[tp[l]];
		if(!fg)v[s3].push_back((sth){st,st+1.0*(dep[l]-dep[tp[l]]+1)/v1,dep[l]-dep[tp[l]]+1,-v1}),st+=1.0*(dep[l]-dep[tp[l]]+1)/v1;
		else v[s3].push_back((sth){et-1.0*(dep[l]-dep[tp[l]]+1)/v1,et,0,v1}),et-=1.0*(dep[l]-dep[tp[l]]+1)/v1;
		l=f[tp[l]];
	}
	int s3=id[tp[l]];
	if(fg)l^=r^=l^=r;
	if(dep[l]<dep[r])v[s3].push_back((sth){st,st+1.0*(dep[r]-dep[l])/v1,dep[l]-dep[tp[l]]+1,v1});
	else v[s3].push_back((sth){st,st+1.0*(dep[l]-dep[r])/v1,dep[l]-dep[tp[l]]+1,-v1});
}
int ch[N][2],rt,fa[N],ct1,id2[N];
double s[N],vl[N],ti,mn=1e18;
priority_queue<double> as,as2;
bool cmp(int a,int b){return s[a]+ti*vl[a]<s[b]+ti*vl[b];}
double calc(int a,int b){if(vl[a]-vl[b]<1e-7&&vl[b]-vl[a]<1e-7)if(s[a]-s[b]<1e-7&&s[b]-s[a]<1e-7)return ti;else return 1e18;double tp=(s[a]-s[b])/(vl[b]-vl[a]);if(tp<ti)return 1e18;return tp;}
void rotate(int x){int f=fa[x],g=fa[f],tp=ch[f][1]==x;ch[g][ch[g][1]==f]=x;fa[x]=g;ch[f][tp]=ch[x][!tp];fa[ch[x][!tp]]=f;ch[x][!tp]=f;fa[f]=x;}
void splay(int x,int y=0){while(fa[x]!=y){int f=fa[x],g=fa[f];if(g!=y)rotate((ch[f][1]==x)^(ch[g][1]==f)?x:f);rotate(x);}if(!y)rt=x;}
int ins(int x,int y){int tp=cmp(x,y);if(!ch[x][tp]){ch[x][tp]=y;fa[y]=x;splay(y,0);return y;}return ins(ch[x][tp],y);}
double doit(int s1)
{
	tp1.clear();
	int sz=v[s1].size();
	for(int i=0;i<sz;i++)tp1.push_back((sth2){v[s1][i].f-1e-9,v[s1][i].s,v[s1][i].v,i,1}),tp1.push_back((sth2){v[s1][i].t,v[s1][i].s,v[s1][i].v,i,-1});
	sort(tp1.begin(),tp1.end());
	ch[1][0]=ch[2][1]=ch[2][0]=0;s[1]=-1e18,s[2]=1e18;vl[1]=vl[2]=0;ch[1][1]=2,fa[2]=1;fa[1]=0;rt=1;ct1=2;
	while(!as.empty())as.pop();while(!as2.empty())as2.pop();
	as.push(-calc(1,2));ti=0;
	for(int i=0;i<sz*2;i++)
	{
		while(as2.size()&&as.top()-as2.top()<=1e-7)as.pop(),as2.pop();
		ti=tp1[i].t;
		if(as.size()&&-as.top()<=tp1[i].t+1e-9)return -as.top();
		if(tp1[i].r==1)
		{
			int st=++ct1;
			fa[st]=ch[st][0]=ch[st][1]=0;s[st]=tp1[i].s-tp1[i].v*ti,vl[st]=tp1[i].v;id2[tp1[i].id]=st;
			ins(rt,st);
			int s1=ch[st][0],s2=ch[st][1];
			while(ch[s1][1])s1=ch[s1][1];
			while(ch[s2][0])s2=ch[s2][0];
			splay(s1);splay(s2);
			as2.push(-calc(s1,s2));
			as.push(-calc(s1,st));
			as.push(-calc(st,s2));
		}
		else
		{
			int st=id2[tp1[i].id];
			splay(st);
			int s1=ch[st][0],s2=ch[st][1];
			while(ch[s1][1])s1=ch[s1][1];
			while(ch[s2][0])s2=ch[s2][0];
			splay(s1);splay(s2,s1);
			as.push(-calc(s1,s2));
			as2.push(-calc(s1,st));
			as2.push(-calc(st,s2));
			ch[s2][0]=fa[st]=0;
		}
	}
	return 1e18;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	dfs1(1,0);dfs2(1,1,0);
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&a,&b,&c,&d),solve(c,d,a,b);
	for(int i=1;i<=n;i++)if(tp[i]==i){double tp=doit(id[i]);if(tp<mn)mn=tp;}
	if(mn<1e18)printf("%.15lf\n",mn);else printf("-1\n");
}//