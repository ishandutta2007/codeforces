#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
typedef double db;
struct pii
{int x,y;
pii(int xx=0,int yy=0){x=xx,y=yy;}};
inline bool operator<(const pii x,cpnst pii y)
{return x.x<y.x;}
int a[1111111];
char str[1111111];
int n,m,k;
#include<queue>
#include<vector>
std::queue<int>q;
std::vector<int>v[1111111],w[1111111];
int dis[1111111],dir[1111111];
void pre(int t)
{
	q.push(t);
	register int i;
	for(i=1;i<=n;i++)dis[i]=1e9;
	dis[t]=0;
	while(!q.empty())
	{
		int p=q.front();q.pop();
		for(i=0;i<v[p].size();i++)
		{
			int to=v[p][i];
			if(dis[to]>dis[p]+1)
			dis[to]=dis[p]+1,
			q.push(to),dir[to]=p;
			else if(dis[to]==dis[p]+1)dir[to]=-1;
		}
	}
}
void exec()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[y].push_back(x);
	}scanf("%d",&k);
	for(i=1;i<=k;i++)
		scanf("%d",&a[i]);
	pre(a[k]);
	int x=0,y=0;
	for(i=1;i<k;i++)
	{
		if(dis[a[i+1]]>=dis[a[i]])x++,y++;
		else if(dir[a[i]]!=a[i+1])y++;
	}printf("%d %d\n",x,y);
}
int main()
{
	int T=1;
//	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/