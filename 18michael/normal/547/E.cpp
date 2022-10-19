#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,q,t=0,edge_t=0,dfn_t=0,qry_t=0;
int c[200002],fa[200002],fail[200002],ans[500002]={},la[200002]={},num[200002],dfn[200002],siz[200002],ed[200002];
char s[200002];
int to[200002][26];
vector<int> vec[200002];
struct aaa
{
	int x,y,o,id;
}qry[1000002];
struct bbb
{
	int to,nx;
}edge[200002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[200002];
	inline void modify(int x)
	{
		while(x<=dfn_t)++sum[x],x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)res+=sum[x],x-=lowbit(x);
		return res;
	}
}S;
inline bool cmp(aaa x,aaa y)
{
	return x.x<y.x? 1:0;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(bbb){y,la[x]},la[x]=edge_t;
}
inline void dfs(int x)
{
	dfn[x]=(++dfn_t),siz[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to),siz[x]+=siz[v];
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,now;i<=n;++i)
	{
		scanf("%s",s+ed[i-1]),ed[i]=strlen(s+ed[i-1])+ed[i-1],now=0;
		for(int j=ed[i-1];j<ed[i];++j)
		{
			if(!to[now][s[j]-'a'])vec[j-ed[i-1]].push_back(to[now][s[j]-'a']=(++t)),fa[t]=now,c[t]=s[j]-'a';
			now=to[now][s[j]-'a'];
		}
		num[i]=now;
	}
	for(int i=0;i<ed[n];++i)
		for(int j=0,k;j<vec[i].size();++j)
		{
			for(k=fail[fa[vec[i][j]]];k && !to[k][c[vec[i][j]]];k=fail[k]);
			if(to[k][c[vec[i][j]]] && to[k][c[vec[i][j]]]!=vec[i][j])fail[vec[i][j]]=to[k][c[vec[i][j]]];
			else fail[vec[i][j]]=0;
			add_edge(fail[vec[i][j]],vec[i][j]);
		}
	for(int i=1,x,y,k;i<=q;++i)
	{
		scanf("%d%d%d",&x,&y,&k),qry[++qry_t]=(aaa){y,k,1,i};
		if(x>1)qry[++qry_t]=(aaa){x-1,k,-1,i};
	}
	sort(qry+1,qry+qry_t+1,cmp),dfs(0);
	for(int i=1,j=1,now;i<=n;++i)
	{
		now=0;
		for(int k=ed[i-1];k<ed[i];++k)S.modify(dfn[now=to[now][s[k]-'a']]);
		while(j<=qry_t && qry[j].x==i)ans[qry[j].id]+=qry[j].o*(S.query(dfn[num[qry[j].y]]+siz[num[qry[j].y]]-1)-S.query(dfn[num[qry[j].y]]-1)),++j;
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}