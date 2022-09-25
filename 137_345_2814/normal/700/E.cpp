#include<cstdio>
#include<queue>
using namespace std;
#define N 400050
#define M 11000500
int rt[N],ch[M][2],sz[M],ct,n,dp[N],pt[N],f[N][21],head[N],cnt,dep[N],in[N],qu[N],ct2,as;
char v[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
struct SAM{
	int ch[N][26],fail[N],len[N],las,ct,st1[N],ct2;
	void ins(int t)
	{
		int s1=las,st=++ct;las=ct;st1[++ct2]=st;len[st]=ct2;
		while(!ch[s1][t]&&s1)ch[s1][t]=st,s1=fail[s1];
		if(!ch[s1][t]){fail[st]=1;return;}
		int tp=ch[s1][t];
		if(len[tp]==len[s1]+1)fail[st]=tp;
		else
		{
			int cl=++ct;len[cl]=len[s1]+1;
			for(int i=0;i<26;i++)ch[cl][i]=ch[tp][i];
			fail[cl]=fail[tp];fail[tp]=fail[st]=cl;
			while(s1&&ch[s1][t]==tp)ch[s1][t]=cl,s1=fail[s1];
		}
	}
}s;
void init()
{
	for(int i=1;i<=n;i++)
	{
		int t=s.st1[i],st=++ct;
		rt[t]=st,sz[st]=1;
		int lb=1,rb=n;
		while(lb!=rb)
		{
			int mid=(lb+rb)>>1;
			if(mid>=i)rb=mid,ch[st][0]=++ct,sz[ct]=1,st=ct;
			else lb=mid+1,ch[st][1]=++ct,sz[ct]=1,st=ct;
		}
	}
}
int merge(int s,int t)
{
	if(!s||!t)return s+t;
	int st=++ct;sz[st]=sz[s]+sz[t];
	ch[st][0]=merge(ch[s][0],ch[t][0]);ch[st][1]=merge(ch[s][1],ch[t][1]);
	return st;
}
int query(int x,int l,int r,int l1,int r1)
{
	if(!x)return 0;
	if(l==l1&&r==r1)return sz[x];
	int mid=(l+r)>>1;
	if(mid>=r1)return query(ch[x][0],l,mid,l1,r1);
	else if(mid<l1)return query(ch[x][1],mid+1,r,l1,r1);
	else return query(ch[x][0],l,mid,l1,mid)+query(ch[x][1],mid+1,r,mid+1,r1);
}
void topsort()
{
	for(int i=1;i<=s.ct;i++)in[s.fail[i]]++;
	queue<int> tp;
	for(int i=1;i<=s.ct;i++)if(!in[i])tp.push(i);
	while(!tp.empty())
	{
		int t=tp.front();tp.pop();qu[++ct2]=t;
		rt[s.fail[t]]=merge(rt[s.fail[t]],rt[t]);
		in[s.fail[t]]--;
		if(!in[s.fail[t]])tp.push(s.fail[t]);
	}
}
void dfs(int u,int fa){f[u][0]=fa;dep[u]=dep[fa]+1;for(int i=1;i<=19;i++)f[u][i]=f[f[u][i-1]][i-1];for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
int doit(int x,int d){for(int i=19;i>=0;i--)if(d>>i&1)x=f[x][i];return x;}
int doit2(int x,int l,int r){if(l==r)return l;int mid=(l+r)>>1;if(ch[x][0])return doit2(ch[x][0],l,mid);else return doit2(ch[x][1],mid+1,r);}
int main()
{
	scanf("%d%s",&n,v+1);s.las=s.ct=1;
	for(int i=1;i<=n;i++)s.ins(v[i]-'a');
	init();topsort();
	for(int i=2;i<=s.ct;i++)adde(s.fail[i],i);dfs(1,0);
	for(int i=ct2-2;i>=1;i--)
	{
		int tp=qu[i],las=pt[s.fail[tp]],tp1=doit2(rt[tp],1,n);
		while(1)
		{
			int nt=doit(tp,dep[tp]-dep[las]-1);
			if(nt==1||query(rt[nt],1,n,tp1-s.len[tp]+s.len[nt],tp1)>=2)las=nt;
			else break;
		}
		pt[tp]=las;dp[tp]=dp[las]+1;if(as<dp[tp])as=dp[tp];
	}
	printf("%d\n",as);
}