#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int N=2000005;
struct node
{
	int id,num;
}p[N];
int n,K,i,j,a[N],Nxt[N],head[N],adj[N],nxt[N],mx[N*5],add[N*5],id[N],size[N];
set<int> st;
set<int>::iterator ddq;
bool cmp(node a,node b)
{
	return a.num>b.num;
}
void pushdown(int o,int l,int r)
{
	add[o<<1]+=add[o],add[o<<1|1]+=add[o];
	mx[o<<1]+=add[o],mx[o<<1|1]+=add[o];
	add[o]=0;
}
void update(int o,int l,int r,int x,int y,int z)
{
	if(l>=x&&r<=y)
	{
		add[o]+=z;
		mx[o]+=z;
		return;
	}
	pushdown(o,l,r);
	int mid=l+r>>1;
	if(x<=mid)
		update(o<<1,l,mid,x,y,z);
	if(y>mid)
		update(o<<1|1,mid+1,r,x,y,z);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void dzx(int i)
{
	update(1,1,n+1,id[i],id[i]+size[i]-1,1);
}
void phh(int i)
{
	update(1,1,n+1,id[i],id[i],-100000000);
}
void dfs(int x)
{
	id[x]=++i;
	size[x]=1;
	for(int y=head[x];y;y=nxt[y])
	{
		dfs(adj[y]);
		size[x]+=size[adj[y]];
	}
}
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		p[i]=(node){i,a[i]};
	}
	sort(p+1,p+1+n,cmp);
	for(i=1;i<=n;i=j)
	{
		for(j=i;j<=n&&p[i].num==p[j].num;++j)
		{
			ddq=st.upper_bound(p[j].id);
			if(ddq!=st.end())
				Nxt[p[j].id]=*ddq;
			else
				Nxt[p[j].id]=n+1;
		}
		for(j=i;j<=n&&p[i].num==p[j].num;++j)
			st.insert(p[j].id);
	}
	for(i=1;i<=n;++i)
	{
		adj[i]=i;
		nxt[i]=head[Nxt[i]];
		head[Nxt[i]]=i;
	}
	i=0;
	dfs(n+1);
	for(i=1;i<=K;++i)
		dzx(i);
	for(i=K;;++i)
	{
		printf("%d ",mx[1]);
		if(i==n)
			break;
		dzx(i+1);
		phh(i-K+1);
	}
	return 0;
}