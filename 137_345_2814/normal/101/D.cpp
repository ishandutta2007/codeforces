#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100040
using namespace std;
long long sz[N],su[N],as;
int n,a,b,c,head[N],cnt,rb,ds[10001];
struct sth{long long a,b;};
vector<sth> s[N];
bool cmp(sth a,sth b){return a.a*b.b>a.b*b.a;}
struct edge{int t,next,v;}ed[N*2];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
void dfs(int u,int fa)
{
	sz[u]=1;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	dfs(ed[i].t,u),sz[u]+=sz[ed[i].t],su[u]+=su[ed[i].t]+ed[i].v*2,s[u].push_back((sth){sz[ed[i].t],su[ed[i].t]+ed[i].v*2}),as+=sz[ed[i].t]*ed[i].v;
	sort(s[u].begin(),s[u].end(),cmp);
	int sz=s[u].size();
	long long st=0;
	for(int i=0;i<sz;i++)
	as+=st*s[u][i].a,st+=s[u][i].b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d%d",&a,&b,&c),adde(a,b,c);
	dfs(1,0);printf("%.10lf\n",1.0*as/(n-1));
}