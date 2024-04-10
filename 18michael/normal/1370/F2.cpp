#include<bits/stdc++.h>
using namespace std;
int n,Test_num,edge_t,rt,d,l,r,mid,X,D,t,mx;
int la[1002],dep[1002],fa[1002];
char s[12];
vector<int> vec[1002];
struct aaa
{
	int to,nx;
}edge[2002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	vec[dep[x]].push_back(x),fa[x]=f;
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f)mx=max(mx,dep[v]=dep[x]+1),dfs(v,x);
}
inline void solve()
{
	scanf("%d",&n),edge_t=mx=0;
	for(int i=1;i<=n;++i)la[i]=0,vec[i-1].clear();
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	printf("? %d ",n);
	for(int i=1;i<=n;++i)printf("%d%c",i,i==n? '\n':' ');
	fflush(stdout),scanf("%d%d",&rt,&d),dfs(rt,dep[rt]=0);
	for(l=(d+1)/2,r=min(d,mx);l<=r;)
	{
		mid=((l+r)>>1),printf("? %d ",vec[mid].size());
		for(int i=0;i<vec[mid].size();++i)printf("%d%c",vec[mid][i],i+1==vec[mid].size()? '\n':' ');
		fflush(stdout),scanf("%d%d",&X,&D);
		if(D==d)t=X,l=mid+1;
		else r=mid-1;
	}
	for(int i=t;i;i=fa[i])dep[i]=-1;
	if(d==r)X=rt;
	else
	{
		printf("? %d",vec[d-r].size()-1);
		for(int i=0;i<vec[d-r].size();++i)if(~dep[vec[d-r][i]])printf(" %d",vec[d-r][i]);
		puts(""),fflush(stdout),scanf("%d%d",&X,&D);
	}
	printf("! %d %d\n",t,X),fflush(stdout),scanf("%s",s);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}