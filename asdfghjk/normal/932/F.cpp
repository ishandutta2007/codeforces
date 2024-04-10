#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200005;
int n,a[N],b[N],i,j,k,head[N],adj[N*2],nxt[N*2],root[N],ch[N*40][2],cnt;
ll K[N*40],B[N*40],f[N];
void update(int &o,int l,int r,ll k,ll b)
{
	if(!o)
	{
		o=++cnt;
		K[o]=k,B[o]=b;
		return;
	}
	int mid=(l+r>=0?(l+r)/2:-((-l-r-1)/2+1));
	double l1=K[o]*l+B[o],r1=K[o]*r+B[o];
	double l2=k*l+b,r2=k*r+b;
	if(l2>=l1&&r2>=r1)
		return;
	if(l2<=l1&&r2<=r1)
	{
		K[o]=k,B[o]=b;
		return;
	}
	double x=1.0*(b-B[o])/(K[o]-k);
	if(l2<l1)
	{
		if(x<=mid)
			update(ch[o][0],l,mid,k,b);
		else
		{
			swap(K[o],k),swap(B[o],b);
			update(ch[o][1],mid+1,r,k,b);
		}
	}
	else
	{
		if(x>mid)
			update(ch[o][1],mid+1,r,k,b);
		else
		{
			swap(K[o],k),swap(B[o],b);
			update(ch[o][0],l,mid,k,b);
		}
	}
}
void merge(int &o1,int o2,int l,int r)
{
	if(!o2)
		return;
	if(!o1)
	{
		o1=o2;
		return;
	}
	if(l==r)
	{
		update(o1,l,r,K[o2],B[o2]);
		return;
	}
	int mid=(l+r>=0?(l+r)/2:-((-l-r-1)/2+1));
	merge(ch[o1][0],ch[o2][0],l,mid);
	merge(ch[o1][1],ch[o2][1],mid+1,r);
	update(o1,l,r,K[o2],B[o2]);
}
ll query(int o,int l,int r,int x)
{
	if(!o)
		return 1ll<<60;
	ll rtn=K[o]*x+B[o];
	int mid=(l+r>=0?(l+r)/2:-((-l-r-1)/2+1));
	if(x<=mid)
		rtn=min(rtn,query(ch[o][0],l,mid,x));
	else
		rtn=min(rtn,query(ch[o][1],mid+1,r,x));
	return rtn;
}
void dfs(int x,int dad)
{
	if(!nxt[head[x]]&&dad!=-1)
	{
		f[x]=0;
		update(root[x],-100000,100000,b[x],0);
		return;
	}
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			merge(root[x],root[adj[y]],-100000,100000);
		}
	f[x]=query(root[x],-100000,100000,a[x]);
	update(root[x],-100000,100000,b[x],f[x]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(i=1;i<=n;++i)
		scanf("%d",b+i);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	dfs(1,-1);
	for(i=1;i<=n;++i)
		printf("%lld ",f[i]);
	return 0;
}