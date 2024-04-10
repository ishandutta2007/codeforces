#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005,md=1000000007;
int ans,n,i,j,k,d,l,s,stk[N],top,a[N],id[N],head[N],adj[N*2],nxt[N*2],f[N],Head[N],Adj[N*2],Nxt[N*2],w[N],cnt,sum[N],u[N],phi[N],p[N],fa[N][20],dep[N];
bool b[N],v[N];
inline int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
bool cmp(int a,int b)
{
	return id[a]<id[b];
}
void addedge(int u,int v,int id)
{
	adj[id*2-1]=v;
	nxt[id*2-1]=head[u];
	head[u]=id*2-1;
	adj[id*2]=u;
	nxt[id*2]=head[v];
	head[v]=id*2;
	//printf("%d %d\n",u,v);
}
void dfs(int x,int dad)
{
	id[x]=++i;
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dep[adj[y]]=dep[x]+1;
			fa[adj[y]][0]=x;
			dfs(adj[y],x);
		}
}
int lca(int a,int b)
{
	int c,d;
	if(dep[a]<dep[b])
		swap(a,b);
	for(c=dep[a]-dep[b],d=0;c;c>>=1,++d)
		if(c&1)
			a=fa[a][d];
	if(a==b)
		return a;
	for(c=18;c>=0;--c)
		if(fa[a][c]!=fa[b][c])
			a=fa[a][c],b=fa[b][c];
	return fa[a][0];
}
void Addedge(int u,int v)
{
	Adj[++l]=v;
	Nxt[l]=Head[u];
	Head[u]=l;
	Adj[++l]=u;
	Nxt[l]=Head[v];
	Head[v]=l;
	//if(i==2)
	//printf("%d %d\n",u,v);
}
void work(int x,int dad)
{	
	sum[x]=b[x]?phi[x]:0;
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
		{
			work(Adj[y],x);
			sum[x]=(sum[x]+sum[Adj[y]])%md;
		}
	int z=(b[x]?1ll*phi[x]*sum[x]%md:0);
	for(int y=Head[x];y;y=Nxt[y])
		if(Adj[y]!=dad)
			z=(z+1ll*(sum[x]-sum[Adj[y]]+md)%md*sum[Adj[y]]%md)%md;
	if(x!=n+1)
		f[i]=(f[i]-2ll*z%md*dep[x]%md+md)%md;
	//if(i==1)
	//printf("%d %d\n",x,f[i]);
}
int main()
{
	scanf("%d",&n);
	phi[1]=u[1]=1;
	for(i=2;i<=n;++i)
	{
		if(!v[i])
		{
			phi[i]=i-1;
			u[i]=-1;
			p[++l]=i;
		}
		for(j=1;j<=l&&p[j]*i<=n;++j)
		{
			v[i*p[j]]=true;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=phi[i]*p[j],u[i*p[j]]=0;
				break;
			}
			else
				phi[i*p[j]]=phi[i]*phi[p[j]],u[i*p[j]]=-u[i];
		}
	}
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		addedge(a[j],a[k],i);
	}
	l=0;
	addedge(n+1,1,n);
	i=0;
	dfs(n+1,-1);
	for(i=1;(1<<i)<=n;++i)
		for(j=1;j<=n+1;++j)
			if(fa[j][i-1])
				fa[j][i]=fa[fa[j][i-1]][i-1];
	for(i=1;i<=n;++i)
	{
		for(j=i,s=0;j<=n;j+=i)
			s=(s+phi[j])%md;
		for(j=i;j<=n;j+=i)
			f[i]=(f[i]+2ll*dep[j]*phi[j]%md*s%md)%md;
		//if(i==1)
		//	printf("%d\n",f[i]);
		w[cnt=1]=stk[top=1]=n+1;
		l=0;
		for(j=i,d=0;j<=n;j+=i)
			a[++d]=j;
		sort(a+1,a+1+d,cmp);
		for(j=1;j<=d;++j)
		{
			//if(i==1)
			//	printf("%d ",j);
			b[a[j]]=true;
			if(lca(a[j],stk[top])==stk[top])
			{
				w[++cnt]=stk[++top]=a[j];
				continue;
			}
			while(top>1)
			{
				k=lca(stk[top],a[j]);
				if(id[stk[top-1]]>id[k])
				{
					Addedge(stk[top-1],stk[top]);
					--top;
				}
				else if(id[stk[top-1]]==id[k])
				{
					Addedge(k,stk[top]);
					--top;
					break;
				}
				else
				{
					Addedge(k,stk[top]);
					w[++cnt]=stk[top]=k;
					break;
				}
			}
			w[++cnt]=stk[++top]=a[j];
		}
		while(top>1)
		{
			Addedge(stk[top-1],stk[top]);
			--top;
		}
		work(n+1,-1);
		for(j=1;j<=cnt;++j)
			Head[w[j]]=0;
		for(j=1;j<=d;++j)
			b[a[j]]=false;
		//printf("%d\n",f[i]);
	}
	for(d=1;d<=n;++d)
	{
		j=0;
		for(k=1;k<=n/d;++k)
			j=(j+1ll*(u[k]+md)*f[d*k]%md)%md;
		ans=(ans+1ll*d*pw(phi[d],md-2)%md*j%md)%md;
	}
	printf("%lld",1ll*ans*pw(n,md-2)%md*pw(n-1,md-2)%md);
	return 0;
}