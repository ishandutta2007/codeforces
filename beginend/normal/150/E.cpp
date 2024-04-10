#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

const int N=100005;
const int inf=1000000000;

int n,L,R,cnt,last[N],w[N],size[N],root,sum,f[N],d[N],g[N],dep[N],que[N],ans,dn[N],gn[N],a1,a2;
bool vis[N],bu[N];
struct data{int to,val,w;};
std::vector<data> vec[N];

int max(int x,int y) {return x>y?x:y;}
int min(int x,int y) {return x<y?x:y;}

void get_root(int x,int fa)
{
	size[x]=1;f[x]=0;
	for (int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i].to;
		if (to==fa||vis[to]) continue;
		get_root(to,x);
		size[x]+=size[to];
		f[x]=max(f[x],size[to]);
	}
	f[x]=max(f[x],sum-size[x]);
	if (!root||f[x]<f[root]) root=x;
}

bool cmp(data x,data y)
{
	return dep[x.to]<dep[y.to];
}

void get_dep(int x,int fa)
{
	dep[x]=0;
	for (int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i].to;
		if (to!=fa&&!vis[to])
			get_dep(to,x),dep[x]=max(dep[x],dep[to]+1);
	}
}

void build(int x)
{
	if (vec[x].size()) return;
	for (int i=0;i<vec[x].size();i++)
	{
		if (vis[vec[x][i].to]) continue;
		get_dep(vec[x][i].to,x);
	}
	sort(vec[x].begin(),vec[x].end(),cmp);
}

void get(int x,int fa,int dep,int val)
{
	if (val>g[dep]) g[dep]=val,gn[dep]=x;size[x]=1;
	for (int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i].to;
		if (to!=fa&&!vis[to]) get(to,x,dep+1,val+vec[x][i].w),size[x]+=size[to];
	}
}

void solve(int x)
{
	vis[x]=1;
	if (!bu[x]) build(x),bu[x]=1;
	d[0]=0;dn[0]=x;
	int mx=0;
	for (int i=0;i<vec[x].size();i++)
	{
		int to=vec[x][i].to;
		if (vis[to]) continue;
		get(to,x,1,vec[x][i].w);
		int l=1,r=0;
		for (int j=min(R-1,mx);j>=L;j--)
		{
			while (l<=r&&d[que[r]]<=d[j]) r--;
			que[++r]=j;
		}
		for (int j=1;g[j]>-inf;j++)
		{
			if (L-j>=0)
			{
				while (l<=r&&d[que[r]]<=d[L-j]) r--;
				que[++r]=L-j;
			}
			while (l<=r&&que[l]>R-j) l++;
			if (l<=r&&g[j]+d[que[l]]>ans) ans=g[j]+d[que[l]],a1=gn[j],a2=dn[que[l]];
		}
		for (int j=1;g[j]>-inf;j++)
		{
			if (g[j]>d[j]) d[j]=g[j],dn[j]=gn[j];
			g[j]=-inf;mx=max(mx,j);
		}
	}
	for (int i=1;d[i]>-inf;i++) d[i]=-inf;
	for (int i=0;i<vec[x].size();i++)
	{
		if (vis[vec[x][i].to]) continue;
		root=0;sum=size[vec[x][i].to];get_root(vec[x][i].to,x);
		solve(root);
	}
}

int main()
{
	scanf("%d%d%d",&n,&L,&R);
	for (int i=1;i<n;i++)
	{
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		vec[x].push_back((data){y,z});
		vec[y].push_back((data){x,z});
		w[i]=z;
	}
	std::sort(w+1,w+n);int w1=std::unique(w+1,w+n)-w-1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<vec[i].size();j++)
			vec[i][j].val=std::lower_bound(w+1,w+w1+1,vec[i][j].val)-w;
	for (int i=0;i<=n;i++) d[i]=g[i]=-inf;
	int l=1,r=w1,b1,b2;
	while (l<=r)
	{
		int mid=(l+r)/2;
		for (int i=1;i<=n;i++)
			for (int j=0;j<vec[i].size();j++)
				vec[i][j].w=vec[i][j].val>=mid?1:-1;
		for (int i=1;i<=n;i++) vis[i]=0;
		root=0;sum=n;get_root(1,0);
		ans=-inf;solve(root);
		if (ans>=0) l=mid+1,b1=a1,b2=a2;
		else r=mid-1;
	}
	printf("%d %d",b1,b2);
	return 0;
}