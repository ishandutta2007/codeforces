#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=100015,DIR[4][2]={0,1,1,0,0,-1,-1,0},INF=0x3f3f3f3f;
const char NAME[4]={'R','D','L','U'}; 

int n,m,src,sink,ss,tt;
int a[MAXN],ty[MAXN],num[MAXN];
inline int calc(int u,int v)
{
	int x=v/m-u/m,y=v%m-u%m;
	for(int t=0;t<4;++t)if(DIR[t][0]==x && DIR[t][1]==y)return t;
	return -1;
}
struct Edge
{
	int v,f;
	Edge *next,*rev;
}*h[MAXN],pool[MAXN*15];
int etot=0;
void addEdge(int u,int v,int f)
{
	Edge *p=&pool[++etot],*q=&pool[++etot];
	p->v=v,p->f=f,p->next=h[u],h[u]=p,p->rev=q;
	q->v=u,q->f=0,q->next=h[v],h[v]=q,q->rev=p;
}
int level[MAXN],q[MAXN];
bool bfs()
{
	int front=1,rear=0;
	for(int i=0;i<=n*m+3;++i)level[i]=INF;
	level[src]=1,q[++rear]=src;
	while(front<=rear)
	{
		int u=q[front++];
		for(Edge *p=h[u];p;p=p->next)
			if(p->f && level[p->v]>level[u]+1)
				level[p->v]=level[u]+1,q[++rear]=p->v;
		if(level[sink]<INF)return 1;
	}
	return 0;
}
int dfs(int u,int key)
{
	if(u==sink)return key;
	int ans=0;
	for(Edge *p=h[u];p;p=p->next)
		if(p->f && level[p->v]==level[u]+1)
		{
			int t=dfs(p->v,min(p->f,key));
			p->f-=t,p->rev->f+=t;
			key-=t,ans+=t;
			if(!key)break;
		}
	if(!ans)level[u]=INF;
	return ans;
}
int dinic()
{
	int ans=0;
	while(bfs())ans+=dfs(src,INF);
	return ans;
}
void solve()
{
	memset(h,0,sizeof(h));
	memset(ty,-1,sizeof(ty));
	memset(num,0,sizeof(num));
	readint(n),readint(m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			readint(a[i*m+j]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			for(int t=0;t<4;++t)
			{
				int x=i+DIR[t][0],y=j+DIR[t][1];
				if(x<0 || x>=n || y<0 || y>=m)continue;
				if(a[i*m+j]>a[x*m+y])ty[i*m+j]=t;
				if(a[i*m+j]==a[x*m+y] && ((i+j)&1))addEdge(i*m+j,x*m+y,1);
			}
	ss=n*m,tt=n*m+1,src=n*m+2,sink=n*m+3;
	int c1=0,c2=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if((i+j)&1)
			{
				if(ty[i*m+j]>=0)addEdge(ss,i*m+j,1);
				else addEdge(src,i*m+j,1),++c1;
			}
			else
			{
				if(ty[i*m+j]>=0)addEdge(i*m+j,tt,1);
				else addEdge(i*m+j,sink,1),++c2;
			}
	addEdge(ss,sink,c1),addEdge(src,tt,c2);
	addEdge(tt,ss,INF);
	int res=dinic();
	if(res<c1+c2){printf("NO\n");return;}
	for(int i=0;i<n*m;++i)
	{
		if(!(((i/m)+(i%m))&1))continue;
		for(Edge *p=h[i];p;p=p->next)
			if(p->v<n*m && p->rev->f)
			{
				ty[i]=calc(i,p->v),ty[p->v]=ty[i]^2;
				num[i]=1,num[p->v]=a[i]-1;
				break;
			}
	}
	for(int i=0;i<n*m;++i)
		if(!num[i])num[i]=a[i]-a[i+DIR[ty[i]][0]*m+DIR[ty[i]][1]];
	printf("YES\n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			printf("%d ",num[i*m+j]);
		putchar('\n');
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			putchar(NAME[ty[i*m+j]]),putchar(' ');
		putchar('\n');
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}