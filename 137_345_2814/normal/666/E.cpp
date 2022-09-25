#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define N 550500
int n,q,ct1=1,tr[N][26],las[N],ct=1,fail[N*2],len[N*2],ch[N*2][26],f[N*2][21],is[N*2],is2[N*2],id[N],as[N][2],head[N*2],cnt,a,b,c,d;
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;}
vector<int> v1[N*2],v2[N];
char s[N];
int insert(int v,int x)
{
	int st=ch[v][x],s1=v;
	if(!st)st=++ct;else return st;
	len[st]=len[s1]+1;
	while(!ch[s1][x])ch[s1][x]=st,s1=fail[s1];
	if(!s1)fail[st]=1;
	else
	{
		int tp=ch[s1][x];
		if(len[tp]==len[s1]+1)fail[st]=tp;
		else
		{
			int cl=++ct;len[cl]=len[s1]+1;
			for(int i=0;i<26;i++)ch[cl][i]=ch[tp][i];
			fail[cl]=fail[tp];fail[tp]=fail[st]=cl;
			while(s1&&ch[s1][x]==tp)ch[s1][x]=cl,s1=fail[s1];
		}
	}
	return st;
}
struct que{int l,r,id;};
vector<que> qu[N*2];
void dfs0(int x)
{
	f[x][0]=fail[x];
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=ed[i].next)dfs0(ed[i].t);
}
#define M 2505000
int rt[M],sn[M][2],mx[M],fr[M],as1,as2,ct2;
void pushup(int x){int fg=mx[sn[x][0]]>=mx[sn[x][1]];if(fg)mx[x]=mx[sn[x][0]],fr[x]=fr[sn[x][0]];else mx[x]=mx[sn[x][1]],fr[x]=fr[sn[x][1]];}
void modify(int x,int l,int r,int v1)
{
	if(l==r){mx[x]++;fr[x]=l;return;}
	int mid=(l+r)>>1;
	if(mid>=v1)
	{
		if(!sn[x][0])sn[x][0]=++ct2;
		modify(sn[x][0],l,mid,v1);
	}
	else
	{
		if(!sn[x][1])sn[x][1]=++ct2;
		modify(sn[x][1],mid+1,r,v1);
	}
	pushup(x);
}
int merge(int x,int y,int l,int r)
{
	if(!x||!y)return x+y;
	if(l==r){mx[x]+=mx[y];fr[x]=max(fr[x],fr[y]);return x;}
	int mid=(l+r)>>1;
	sn[x][0]=merge(sn[x][0],sn[y][0],l,mid);
	sn[x][1]=merge(sn[x][1],sn[y][1],mid+1,r);
	pushup(x);return x;
}
void query(int x,int l,int r,int l1,int r1)
{
	if(!x)return;
	if(l==l1&&r==r1){if(mx[x]&&(as2<mx[x]||(as2==mx[x]&&as1>fr[x])))as2=mx[x],as1=fr[x];return;}
	int mid=(l+r)>>1;
	if(mid>=r1)query(sn[x][0],l,mid,l1,r1);
	else if(mid<l1)query(sn[x][1],mid+1,r,l1,r1);
	else query(sn[x][0],l,mid,l1,mid),query(sn[x][1],mid+1,r,mid+1,r1);
}
void dfs1(int u)
{
	rt[u]=++ct2;
	for(int i=head[u];i;i=ed[i].next)dfs1(ed[i].t),rt[u]=merge(rt[u],rt[ed[i].t],1,n);
	for(int i=0;i<v1[u].size();i++)
	modify(rt[u],1,n,v1[u][i]);
	for(int i=0;i<qu[u].size();i++)
	{
		as1=qu[u][i].l;as2=0;
		query(rt[u],1,n,qu[u][i].l,qu[u][i].r);
		as[qu[u][i].id][0]=as1;as[qu[u][i].id][1]=as2;
	}
}
int main()
{
	scanf("%s",s+1);
	int st=1;
	for(int i=1;s[i];i++)
	{
		int tp=s[i]-'a';
		if(!tr[st][tp])tr[st][tp]=++ct1;
		st=tr[st][tp];
		is[st]=i;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int st=1;
		for(int j=1;s[j];j++)
		{
			int tp=s[j]-'a';
			if(!tr[st][tp])tr[st][tp]=++ct1;
			st=tr[st][tp];
			v2[st].push_back(i);
		}
	}
	las[1]=1;queue<int> tp;tp.push(1);
	while(!tp.empty())
	{
		int s=tp.front();tp.pop();
		for(int i=0;i<26;i++)if(tr[s][i])las[tr[s][i]]=insert(las[s],i),tp.push(tr[s][i]);
		if(is[s])id[is[s]]=las[s];
		v1[las[s]]=v2[s];
	}
	for(int i=2;i<=ct;i++)adde(fail[i],i);
	dfs0(1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&c,&d,&a,&b);
		int tp=id[b],le=b-a+1;
		for(int j=20;j>=0;j--)if(len[f[tp][j]]>=le)tp=f[tp][j];
		qu[tp].push_back((que){c,d,i});
	}
	dfs1(1);
	for(int i=1;i<=q;i++)printf("%d %d\n",as[i][0],as[i][1]);
}