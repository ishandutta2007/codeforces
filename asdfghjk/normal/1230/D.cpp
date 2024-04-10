#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=7005;
int n,i,j,k,l,b[N],len[N],rlen[N],id[N],cnt,sz[N],col[N];
short adj[N][N],radj[N][N];
ll a[N],sum[N],ans;
bool v[N];
void dfs(int x)
{
	v[x]=true;
	for(int y=1;y<=len[x];++y)
		if(!v[adj[x][y]])
			dfs(adj[x][y]);
	id[++j]=x;
}
void rdfs(int x)
{
	++sz[j];
	col[x]=j;
	v[x]=true;
	sum[j]+=b[x];
	for(int y=1;y<=rlen[x];++y)
		if(!v[radj[x][y]])
			rdfs(radj[x][y]);
}
void work(int x)
{
	v[x]=true;
	for(int y=1;y<=rlen[x];++y)
		if(!v[radj[x][y]])
			work(radj[x][y]);
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%I64d",a+i);
	for(i=1;i<=n;++i)
		scanf("%d",b+i);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(i!=j&&(a[i]&a[j])==a[j])
			{
				adj[i][++len[i]]=j;
				radj[j][++rlen[j]]=i;
			}
	for(i=1,j=0;i<=n;++i)
		if(!v[i])
			dfs(i);
	for(i=1;i<=n;++i)
		v[i]=false;
	for(i=n,j=0;i>=1;--i)
		if(!v[id[i]])
		{
			++j;
			rdfs(id[i]);
		}
	cnt=j;
	for(i=1;i<=cnt;++i)
		rlen[i]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=len[i];++j)
			if(col[i]!=col[adj[i][j]])
				radj[col[i]][++rlen[col[i]]]=col[adj[i][j]];
	for(i=1;i<=cnt;++i)
		v[i]=false;
	for(i=1;i<=cnt;++i)
		if(sz[i]>1&&!v[i])
			work(i);
	for(i=1;i<=cnt;++i)
		if(v[i])
			ans+=sum[i];
	printf("%I64d",ans);
	return 0;
}