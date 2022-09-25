#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
#define N 1250050
#define M 2500080
int n,m,a,b,c,d,head[N],cnt,fa[N],id[N],le[N],id2[N],tp[N],ed1[N],ct,dep[N],sz[N],son[N],c1,f[N];
char s[N];
struct SA{
	int sa[M],rk[M],a[M],b[M],su[M],n,m,he[N],mn[N][21],lg[N];
	char v[M];
	void init()
	{
		m=n+255;
		for(int i=1;i<=n;i++)su[a[i]=v[i]]++;
		for(int i=1;i<=m;i++)su[i]+=su[i-1];
		for(int i=n;i>=1;i--)sa[su[a[i]]--]=i;
		for(int k=1;k<=n;k<<=1)
		{
			int ct=0;
			for(int i=n;i>n-k;i--)b[++ct]=i;
			for(int i=1;i<=n;i++)if(sa[i]>k)b[++ct]=sa[i]-k;
			for(int i=1;i<=m;i++)su[i]=0;
			for(int i=1;i<=n;i++)su[a[i]]++;
			for(int i=1;i<=m;i++)su[i]+=su[i-1];
			for(int i=n;i>=1;i--)sa[su[a[b[i]]]--]=b[i];
			ct=2;
			for(int i=1;i<=n;i++)b[i]=a[i];
			a[sa[1]]=1;
			for(int i=2;i<=n;i++)a[sa[i]]=b[sa[i]]==b[sa[i-1]]&&b[sa[i]+k]==b[sa[i-1]+k]?ct-1:ct++;
		}
		for(int i=1;i<=n;i++)rk[sa[i]]=i;
		int ls=0;s[n+1]='%';
		for(int i=1;i<=n;i++)
		{
			if(ls)ls--;
			if(rk[i]==1)continue;
			while(v[i+ls]==v[sa[rk[i]-1]+ls])ls++;
			he[rk[i]]=ls;
		}
		for(int i=2;i<=n;i++)mn[i][0]=he[i];
		for(int j=1;j<=20;j++)
		for(int i=2;i+(1<<j)-1<=n;i++)
		mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	}
	int query(int l,int r)
	{
		if(l==r)return 1e9;
		if(l>r)l^=r^=l^=r;
		l++;
		int tp=lg[r-l+1];
		return min(mn[l][tp],mn[r-(1<<tp)+1][tp]);
	}
}sa;
struct edge{int t,next;}ed[N];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs1(int u,int fa)
{
	sz[u]=1;dep[u]=dep[fa]+1;f[u]=fa;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs1(ed[i].t,u);
		if(sz[son[u]]<sz[ed[i].t])son[u]=ed[i].t;
		sz[u]+=sz[ed[i].t];
	}
}
void dfs2(int u,int v,int fa)
{
	tp[u]=v;
	int fg=0;
	if(son[u])dfs2(son[u],v,u);
	else
	{
		int s1=tp[u],st=u,ct=dep[st]-dep[s1]+1;
		le[s1]=ct;id[s1]=c1+1;
		stack<char> q;
		q.push(s[u]);sa.v[++c1]=s[u];
		ed1[u]=u;
		while(st!=s1)
		{
			st=f[st];ed1[st]=u;
			q.push(s[st]);sa.v[++c1]=s[st];
		}
		sa.v[++c1]='$';
		id2[s1]=c1+1;
		while(!q.empty())sa.v[++c1]=q.top(),q.pop();
		sa.v[++c1]='$';
		return;
	}
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&ed[i].t!=son[u])
	dfs2(ed[i].t,ed[i].t,u);
}
struct sth{int l,r;};
vector<sth> tp1,tp2;
void solve1(int a,int b,vector<sth> &c)
{
	c.clear();
	stack<sth> sb;
	int fg=0;
	while(tp[a]!=tp[b])
	{
		if(dep[tp[a]]<dep[tp[b]])a^=b^=a^=b,fg^=1;
		if(!fg)c.push_back((sth){id[tp[a]]+le[tp[a]]-1-dep[a]+dep[tp[a]],id[tp[a]]+le[tp[a]]-1});
		else sb.push((sth){id2[tp[a]],id2[tp[a]]+dep[a]-dep[tp[a]]});
		a=f[tp[a]];
	}
	if(fg)a^=b^=a^=b;
	if(dep[a]>=dep[b])c.push_back((sth){id[tp[a]]+le[tp[a]]-1-dep[a]+dep[tp[a]],id[tp[a]]+le[tp[a]]-1-dep[b]+dep[tp[a]]});
	else c.push_back((sth){id2[tp[a]]+dep[a]-dep[tp[a]],id2[tp[a]]+dep[b]-dep[tp[a]]});
	while(!sb.empty())c.push_back(sb.top()),sb.pop();
}
int solve()
{
	int as=0,s1=tp1.size(),s2=tp2.size(),l1=0,l2=0;
	while(l1!=s1&&l2!=s2)
	{
		int lb1=tp1[l1].l,rb1=tp1[l1].r,lb2=tp2[l2].l,rb2=tp2[l2].r;
		int lcp=sa.query(sa.rk[lb1],sa.rk[lb2]);
		if(lcp>min(rb1-lb1+1,rb2-lb2+1))lcp=min(rb1-lb1+1,rb2-lb2+1);
		as+=lcp;
		if(lb1+lcp-1<rb1&&lb2+lcp-1<rb2)return as;
		lb1+=lcp;lb2+=lcp;
		if(lb1<=rb1)tp1[l1].l=lb1;else l1++;
		if(lb2<=rb2)tp2[l2].l=lb2;else l2++;
	}
	return as;
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	dfs1(1,0);dfs2(1,1,0);
	sa.n=c1;
	sa.init();
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		solve1(a,b,tp1);solve1(c,d,tp2);
		printf("%d\n",solve());
	}
}//(300000+300000)*2=1.2e6