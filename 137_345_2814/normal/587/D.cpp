#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
#include<algorithm>
#include<stack>
using namespace std;
#define N 500500
int s[N][4],n,m,head[N],cnt,ct,dfn[N],low[N],scc[N],s1[N],ct1,ct2;
struct edge{int t,next;}ed[N*4];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;}
stack<int> tp;
vector<int> st[N];
set<int> vl;
bool cmp(int i,int j){return s[i][2]<s[j][2];}
void dfs1(int u)
{
	dfn[u]=low[u]=++ct1;
	tp.push(u);
	for(int i=head[u];i;i=ed[i].next)
	{
		if(!dfn[ed[i].t])dfs1(ed[i].t),low[u]=min(low[u],low[ed[i].t]);
		else if(!scc[ed[i].t])low[u]=min(low[u],dfn[ed[i].t]);
	}
	if(dfn[u]==low[u])
	{
		int s=tp.top(),id=++ct2;tp.pop();
		scc[s]=id;
		while(s!=u)
		s=tp.top(),tp.pop(),scc[s]=id;
	}
}
bool check(int v)
{
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	cnt=0;
	ct=m*2;ct1=0;ct2=0;
	for(int i=1;i<=m;i++)if(s[i][3]<=v)st[s[i][0]].push_back(i),st[s[i][1]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		int sz=st[i].size();
		for(int j=0;j<sz;j++)
		{
			adde(ct+j+1,st[i][j]+m),adde(ct+j+sz+1,st[i][j]+m);
			if(j)adde(st[i][j],ct+j),adde(ct+j+1,ct+j),adde(ct+sz+j,ct+sz+j+1);
			if(j<sz-1)adde(st[i][j],ct+j+sz+2);
		}
		ct+=sz*2;
		st[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		vl.insert(s[s1[i]][0]);vl.insert(s[s1[i]][1]);
		st[s[s1[i]][0]].push_back(s1[i]+m),st[s[s1[i]][1]].push_back(s1[i]+m);
		if(i==m||s[s1[i]][2]!=s[s1[i+1]][2])
		{
			for(set<int>::iterator it=vl.begin();it!=vl.end();it++)
			{
				int x=*it;
				int sz=st[x].size();
				for(int j=0;j<sz;j++)
				{
					adde(ct+j+1,st[x][j]-m),adde(ct+j+sz+1,st[x][j]-m);
					if(j)adde(st[x][j],ct+j),adde(ct+j+1,ct+j),adde(ct+sz+j,ct+sz+j+1);
					if(j<sz-1)adde(st[x][j],ct+j+sz+2);
				}
				ct+=sz*2;
				st[x].clear();
			}
			vl.clear();
		}
	}
	for(int i=1;i<=m;i++)if(s[i][3]>v)adde(i,i+m);
	for(int i=1;i<=ct;i++)if(!dfn[i])dfs1(i);
	for(int i=1;i<=m;i++)if(scc[i]==scc[i+m])return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&s[i][0],&s[i][1],&s[i][2],&s[i][3]),s1[i]=i;
	sort(s1+1,s1+m+1,cmp);
	if(!check(1e9+9)){printf("No\n");return 0;}
	int lb=0,rb=1e9,as=1e9;
	while(lb<=rb)
	{
		int mid=(lb+rb)>>1;
		if(check(mid))
		as=mid,rb=mid-1;
		else lb=mid+1;
	}
	check(as);
	printf("Yes\n");
	int c1=0;
	for(int i=1;i<=m;i++)
	if(scc[i+m]>scc[i])c1++;
	printf("%d %d\n",as,c1);
	for(int i=1;i<=m;i++)if(scc[i+m]>scc[i])printf("%d ",i);
}