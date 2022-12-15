#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
class edge
{
	public:
		int e,nxt;
		bool f;
}g[400010];
int ecnt=0;
int head[200010];
void addedge(int s,int e)
{
	g[ecnt]=(edge){e,head[s],1},head[s]=ecnt++;
	g[ecnt]=(edge){s,head[e],0},head[e]=ecnt++;
}
int n,m,S,T,K,p[200010],dis[200010];
void dijkstra()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	memset(dis,0x3f,sizeof(dis));
	q.push(make_pair(0,T));
	dis[T]=0;
	while(!q.empty())
	{
		auto fr=q.top();q.pop();
		if(dis[fr.second]!=fr.first)continue;
		for(int i=head[fr.second];i!=-1;i=g[i].nxt)
		{
			if(!g[i].f&&dis[g[i].e]>fr.first+1)
			{
				dis[g[i].e]=fr.first+1;
				q.push(make_pair(dis[g[i].e],g[i].e));
			}
		}
	}
}
int main()
{
	memset(head,255,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1,ti,tj;i<=m;i++)
	{
		scanf("%d%d",&ti,&tj);
		addedge(ti,tj);
	}
	scanf("%d",&K);
	for(int i=1;i<=K;i++)scanf("%d",&p[i]);
	S=p[1];T=p[K];
	dijkstra();
	int mn=0,mx=0;
	for(int i=1;i<K;i++)
	{
		int cnt=0;
		for(int j=head[p[i]];j!=-1;j=g[j].nxt)
		{
			if(g[j].f&&dis[g[j].e]+1==dis[p[i]])cnt++;
		}
		if(dis[p[i+1]]+1!=dis[p[i]])mn++,mx++;
		else if(cnt!=1)mx++;
	}
	printf("%d %d\n",mn,mx);
	return 0;
}