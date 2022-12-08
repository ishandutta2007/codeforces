#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
const int N=3e5+5,M=1e7+5;
struct E{int to,next;};
struct Graph
{
	E edge[M];
	int head[N],tot;
	inline void init(){memset(head,-1,sizeof(head));tot=0;}
	inline void addedge(int x,int y){edge[++tot]=(E){y,head[x]};head[x]=tot;}
};
struct TwoSAT
{
	Graph G1,G2;
	int n,dfn[N],low[N],ins[N],stk[N],top,Time,fa[N],cnt,in[N],col[N],mark[N];
	vector<int> vec[N];
	inline void init(int n)
	{
		this->n=n;G1.init();G2.init();
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(ins,0,sizeof(ins));
		memset(in,0,sizeof(in));
		memset(col,-1,sizeof(col));
		for(int i=1;i<=2*n;i++)vec[i].clear();
		top=0;Time=0;cnt=0;
	}
	inline void add(int x,int xval,int y,int yval)
	{
		x=x*2+xval;y=y*2+yval;
		G1.addedge(x^1,y);G1.addedge(y^1,x);
	}
	inline void add(int x,int xval)
	{
		x=x*2+xval;
		G1.addedge(x^1,x);
	}
	void tarjan(int u)
	{
		dfn[u]=low[u]=++Time;
		stk[++top]=u;ins[u]=1;
		for(int i=G1.head[u];i!=-1;i=G1.edge[i].next)
			if(!dfn[G1.edge[i].to])tarjan(G1.edge[i].to),low[u]=min(low[u],low[G1.edge[i].to]);
			else if(ins[G1.edge[i].to])low[u]=min(low[u],dfn[G1.edge[i].to]);
		if(dfn[u]==low[u])
		{
			cnt++;
			while(true)
			{
				int x=stk[top--];
				ins[x]=0;fa[x]=cnt;
				vec[cnt].push_back(x);
				if(x==u)break;
			}
		}
	}
	void paint(int u)
	{
		col[u]=0;
		for(int i=G2.head[u];i!=-1;i=G2.edge[i].next)if(col[G2.edge[i].to]==-1)paint(G2.edge[i].to);
	}
	inline bool solve()
	{
		for(int i=0;i<2*n;i++)if(!dfn[i])tarjan(i);
		for(int i=0;i<n;i++)if(fa[2*i]==fa[2*i+1])return false;
		for(int i=0;i<2*n;i++)
			for(int j=G1.head[i];j!=-1;j=G1.edge[j].next)
				if(fa[i]!=fa[G1.edge[j].to])G2.addedge(fa[G1.edge[j].to],fa[i]),in[fa[i]]++;
		queue<int> Q;
		for(int i=1;i<=cnt;i++)if(!in[i])Q.push(i);
		while(!Q.empty())
		{
			int x=Q.front();Q.pop();
			if(col[x]==-1)
			{
				col[x]=1;
				for(int i=0;i<vec[x].size();i++)if(col[fa[vec[x][i]^1]]==-1)paint(fa[vec[x][i]^1]);
			}
			for(int i=G2.head[x];i!=-1;i=G2.edge[i].next)if(--in[G2.edge[i].to]==0)Q.push(G2.edge[i].to);
		}
		for(int i=0;i<2*n;i++)mark[i]=col[fa[i]];
	}
}solver;
int n,m,u[N],v[N],c[N],t[N],a[N],num[N];
vector<int> vec[N],link[N];
map<int,int> mp;
inline bool check(int x)
{
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<link[i].size();j++)if(t[link[i][j]]>x)
		{
			num[c[link[i][j]]]++;
			if(num[c[link[i][j]]]>1)flag=false;
		}
		for(int j=0;j<link[i].size();j++)if(t[link[i][j]]>x)num[c[link[i][j]]]--;
	}
	if(!flag)return false;
	solver.init(3*m);
	int now=0;
	vector<int> tmp;tmp.clear();
	for(int i=1;i<=n;i++)
	{
		int sz=(int)link[i].size(),flag=0,pos=-1;
		for(int j=1;j<sz;j++)if(c[link[i][j]]==c[link[i][j-1]])
		{
			if(t[link[i][j]]<=x&&t[link[i][j-1]]<=x)solver.add(link[i][j]-1,1,link[i][j-1]-1,1);
			else if(t[link[i][j]]<=x)flag=1,pos=j;else flag=1,pos=j-1;
		}
		if(flag)tmp.push_back(link[i][pos]);
		for(int j=0;j<sz;j++)if(t[link[i][j]]<=x)solver.add(link[i][j]-1,0,now+m+j,1);
		for(int j=1;j<sz;j++)solver.add(now+m+j-1,0,now+m+j,1);
		for(int j=0;j<sz-1;j++)if(t[link[i][j+1]]<=x)solver.add(now+m+j,0,link[i][j+1]-1,0);
		now+=sz;
	}
	for(int i=0;i<tmp.size();i++)solver.add(tmp[i]-1,1);//if(!solver.dfs(2*(tmp[i]-1)+1))return false;
	if(solver.solve())return true;
	return false;
}
inline bool cmp(int a,int b){return c[a]<c[b];}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&u[i],&v[i],&c[i],&t[i]),a[i]=c[i],link[u[i]].push_back(i),link[v[i]].push_back(i);
	for(int i=1;i<=n;i++)sort(link[i].begin(),link[i].end(),cmp);
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)mp[a[i]]=i;
	for(int i=1;i<=m;i++)c[i]=mp[c[i]],vec[c[i]].push_back(i);
	bool flag=true;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			num[u[vec[i][j]]]++,num[v[vec[i][j]]]++;
			if(num[u[vec[i][j]]]>2)flag=false;
			if(num[v[vec[i][j]]]>2)flag=false;
		}
		for(int j=0;j<vec[i].size();j++)num[u[vec[i][j]]]--,num[v[vec[i][j]]]--;
	}
	if(!flag)return puts("No"),0;
	int L=0,R=1e9;
	while(L<R)
	{
		int mid=(L+R)>>1;
		if(check(mid))R=mid;
		else L=mid+1;
	}
	if(check(R))
	{
		puts("Yes");
		int cnt=0;
		for(int i=1;i<=m;i++)if(solver.mark[2*i-1])cnt++;
		printf("%d %d\n",R,cnt);
		for(int i=1;i<=m;i++)if(solver.mark[2*i-1])printf("%d ",i);
	}
	else puts("No");
	return 0;
}