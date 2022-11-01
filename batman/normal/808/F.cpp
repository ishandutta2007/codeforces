#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)110)
#define K ((ll)201*1000)
#define M ((ll)N*N)
#define INF ((ll)2e9)

int from[M],to[M],prv[M];
ll cap[M];
int head[N],ptr[N],ecnt;
int q[N];
ll d[N];
 
void add_edge(int u,int v,ll uv,ll vu=0)
{
	from[ecnt]=u,to[ecnt]=v,cap[ecnt]=uv,prv[ecnt]=head[u],head[u]=ecnt++;
	from[ecnt]=v,to[ecnt]=u,cap[ecnt]=vu,prv[ecnt]=head[v],head[v]=ecnt++;
}
 
bool bfs(int source,int sink)
{
	memset(d,63,sizeof d);
	int h=0,t=0;
	q[t++]=source;
	d[source]=0;
	while(h<t)
	{
		int v=q[h++];
		for(int i=head[v];i!=-1;i=prv[i])
			if(cap[i] && d[to[i]]>d[v]+1)
			{
				d[to[i]]=d[v]+1;
				q[t++]=to[i];
			}
	}
	return d[sink]<=1e9;
}
 
ll dfs(int v,int sink,ll f=INF)
{
	if(sink==v)
		return f;
	ll out=0;
	for(;ptr[v]!=-1;ptr[v]=prv[ptr[v]])
		if(d[to[ptr[v]]]==d[v]+1)
		{
			ll x=dfs(to[ptr[v]],sink,min(f,cap[ptr[v]]));
			cap[ptr[v]]-=x;
			cap[ptr[v]^1]+=x;
			out+=x;
			f-=x;
			if(f==0)break;
		}
	return out;
}
 
ll maxflow(int source,int sink)
{
	ll out=0;
	while(bfs(source,sink))
	{
		memcpy(ptr,head,sizeof head);
		out+=dfs(source,sink);
	}
	return out;
}

struct Card
{
	ll p,c,l;
};

ll n,k;
bool prime[K];
Card a[N];

bool check(int x)
{
	ll all=0;
	ecnt=0;
	for(int i=0;i<N;i++)head[i]=-1;
	ll max_1=-1,id=0;
	for(int i=1;i<=n;i++)
		if(a[i].l<=x)
		{
			if(a[i].c%2==0)
			{
				add_edge(0,i,a[i].p);all+=a[i].p;
				for(int j=1;j<=n;j++)
					if(a[j].l<=x && a[j].c%2==1 && !prime[a[i].c+a[j].c])
						add_edge(i,j,(ll)1e12);
			}
			else
			{
				if(a[i].c!=1)add_edge(i,n+1,a[i].p),all+=a[i].p;
				else if(a[i].p>max_1)max_1=a[i].p,id=i;
			}
		}
	if(max_1!=-1)add_edge(id,n+1,max_1),all+=max_1;
	return all-maxflow(0,n+1)>=k;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=2;i<K;i++)
		if(!prime[i])
			for(int j=2*i;j<K;j+=i)
				prime[j]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i].p>>a[i].c>>a[i].l;
	int l=0,r=102;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r==102)return cout<<-1,0;
	cout<<r;
	return 0;
}