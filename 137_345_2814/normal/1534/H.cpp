#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100500
int n,a,b,head[N],cnt,dp[N],dp2[N],pr[N],su[N],f,vl[N],as1[N],f1[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
vector<pair<int,int> > st[N],s2[N];
void dfs0(int u,int fa)
{
	st[u].clear();f1[u]=fa;
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs0(ed[i].t,u),st[u].push_back((make_pair(dp[ed[i].t],ed[i].t)));
	if(!st[u].size()){dp[u]=1;vl[u]=u;return;}
	sort(st[u].begin(),st[u].end());
	int tp=-1;
	for(int i=0;i<st[u].size();i++)
	{
		tp++;
		if(tp<=st[u][i].first)vl[u]=vl[st[u][i].second],tp=st[u][i].first;
	}
	dp[u]=tp;
}
void dfs1(int u,int fa)
{
	s2[u]=st[u];
	if(u!=1&&dp2[u]==0)dp2[u]=1;
	if(u!=1)s2[u].push_back(make_pair(dp2[u],fa));
	sort(s2[u].begin(),s2[u].end());
	int sz=s2[u].size();
	for(int i=0;i<=sz;i++)pr[i]=su[i]=0;
	for(int i=0;i<sz;i++)pr[i]=max((i?pr[i-1]:0),s2[u][i].first+(sz-i)-1);
	for(int i=sz-1;i>=0;i--)su[i]=max(su[i+1],s2[u][i].first+(sz-i)-1);
	for(int i=0;i<sz;i++)if(s2[u][i].second!=fa)dp2[s2[u][i].second]=max((i?pr[i-1]-1:0),su[i+1]);
	for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs1(ed[i].t,u);
}
int query(int x){if(as1[x])return as1[x];printf("? %d\n",x);fflush(stdout);int as=0;scanf("%d",&as);return as1[x]=as;}
int doit(int x)
{
	for(int i=0;i<st[x].size();i++)if(query(vl[st[x][i].second])!=x)return doit(st[x][i].second);
	return x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	dfs0(1,0);dfs1(1,0);
	int mx=0;
	for(int u=1;u<=n;u++)if(s2[u].size())
	{
		int s1=s2[u].size();
		for(int i=0;i+1<s2[u].size();i++)s1=max(s1,s2[u][i].first-1+((int)s2[u].size()-i));
		s1+=s2[u][s2[u].size()-1].first-1;
		mx=max(mx,s1);
	}
	printf("%d\n",mx);fflush(stdout);
	scanf("%d",&f);dfs0(f,0);
	int v1=0,v2=0;
	for(int i=1;i<=n;i++)reverse(st[i].begin(),st[i].end());
	for(int i=0;i<st[f].size();i++)
	{
		int s1=query(vl[st[f][i].second]);
		if(s1!=f){if(!v1)v1=st[f][i].second;else v2=st[f][i].second;}
		if(v2)break;
	}
	if(!v1)v1=f;else v1=doit(v1);
	if(!v2)v2=f;else v2=doit(v2);
	printf("! %d %d\n",v1,v2);
}