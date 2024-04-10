#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int A[111];
int B[111];
int N,M;
vector<int> conn[999];
int flow[999];
int flowed[999];
int s[999];
int e[999];
int sz=0;
int tp[111][111];
bool vis[999];
int aug(int a,int b) //a: no, b: flow ryou
{
	if(vis[a]) return 0;
	vis[a]=true;
	//printf("<%d %d>\n",a,b);
	if(a==2*N+1)
		return b;
	for(int i=0;i<conn[a].size();i++)
	{
		int V=conn[a][i];
		int dest,x;
		if(s[V]==a)
		{
			dest=e[V];
			x=min(b,flow[V]-flowed[V]);
		}
		else
		{
			dest=s[V];
			x=min(b,flowed[V]);
		}
		if(!x) continue;
		int r=aug(dest,x);
		if(!r) continue;
		if(s[V]==a)
			flowed[V]+=r;
		else
			flowed[V]-=r;
		return r;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&N,&M);
	int asum=0,bsum=0;
	for(int i=1;i<=N;i++)
	{
		flow[sz]=987654321;
		s[sz]=i;
		e[sz]=i+N;
		conn[i].push_back(sz);
		conn[i+N].push_back(sz);
		sz++;
	}
	for(int i=1;i<=N;i++)
	{
		int t;
		scanf("%d",&t);
		asum+=t;
		flow[sz]=t;
		s[sz]=0;
		e[sz]=i;
		conn[0].push_back(sz);
		conn[i].push_back(sz);
		sz++;
	}
	for(int i=1;i<=N;i++)
	{
		int t;
		scanf("%d",&t);
		bsum+=t;
		flow[sz]=t;
		s[sz]=i+N;
		e[sz]=2*N+1;
		conn[i+N].push_back(sz);
		conn[2*N+1].push_back(sz);
		sz++;
	}
	for(int i=0;i<M;i++)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		flow[sz]=987654321;
		s[sz]=a;
		e[sz]=b+N;
		conn[a].push_back(sz);
		conn[b+N].push_back(sz);
		sz++;
		flow[sz]=987654321;
		s[sz]=b;
		e[sz]=a+N;
		conn[b].push_back(sz);
		conn[a+N].push_back(sz);
		sz++;
	}
	int ans=0;
	while(true)
	{
		for(int i=0;i<2*N+2;i++) vis[i]=false;
		int v=aug(0,987654321);
		ans+=v;
		if(v==0) break;
	}
	//printf("%d",ans);
	if(ans!=asum || asum!=bsum)
	{
		puts("NO");
		return 0;	
	}
	puts("YES");
	for(int i=0;i<sz;i++)
	{
		int x=s[i];
		int y=e[i];
		if(1<=x && x<=N && N+1<=y && y<=2*N)
		{
			y-=N;
			tp[x-1][y-1]=flowed[i];
		}
	}
	for(int i=0;i<N;i++,puts(""))
		for(int j=0;j<N;j++)
			printf("%d ",tp[i][j]);
	return 0;
}