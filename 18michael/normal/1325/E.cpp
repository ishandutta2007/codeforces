#include<bits/stdc++.h>
#define Mx 1000000
using namespace std;
int n,p_t=0,ans,vec_t=0,edge_t=1;
int mnp[1000002],p[1000002],num[1000002],dis[1000002],la[1000002];
bool u[100002];
queue<int> q;
struct aaa
{
	int to,nx;
}edge[200002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void init()
{
	for(int i=1;i<=Mx;++i)num[i]=i;
	mnp[1]=p[0]=1;
	for(int i=2,i2;i<=Mx;++i)
	{
		if(!mnp[i])
		{
			p[++p_t]=mnp[i]=i;
			if(i<=Mx/i)
			{
				i2=i*i;
				for(int j=i2;j<=Mx;j+=i2)for(;!(num[j]%i2);num[j]/=i2);
			}
		}
		for(int j=1;j<=p_t && p[j]*i<=Mx;++j)
		{
			mnp[p[j]*i]=p[j];
			if(!(i%p[j]))break;
		}
	}
}
inline void bfs(int x)
{
	for(int i=0;i<=p_t;++i)dis[p[i]]=Mx;
	for(int i=(edge_t>>1);i;--i)u[i]=0;
	int p;
	for(q.push(x),dis[x]=0;q.size();)
	{
		p=q.front(),q.pop();
		for(int i=la[p],v;i;i=edge[i].nx)
			if(!u[i>>1])
			{
				u[i>>1]=1;
				if(dis[v=edge[i].to]<Mx)ans=min(ans,dis[v]+dis[p]+1);
				else dis[v]=dis[p]+1,q.push(v);
			}
	}
}
int main()
{
	init(),scanf("%d",&n),ans=n+1;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if((x=num[x])==1)return 0&printf("1");
		add_edge(mnp[x],x/mnp[x]);
	}
	for(int i=1;i*i<=Mx;++i)if(mnp[i]==i)bfs(i);
	return 0&printf("%d",ans<=n? ans:-1);
}