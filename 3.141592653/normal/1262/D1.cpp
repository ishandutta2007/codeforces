#include<cstdio>
#include<cstring>
#include<queue>
using std::priority_queue;
typedef long long ll;
typedef double db;
int n;
int a[2121111];
struct pii
{int v,t;};
inline bool operator<(const pii x,const pii y)
{
	if(x.v^y.v)return x.v>y.v;
	return x.t<y.t;
}
priority_queue<pii>q;
#include<vector>
std::vector<int>v[211111],vt[211111];
int m;
#define lowbit(x) (x&(-x))
int tra[2222222],ans[2222222];
inline void add(int x,int del)
{
	for(;x<=200000;x+=lowbit(x))tra[x]+=del;
}
inline int locate(int k)
{
	int t=131072,p=0;
	for(;t;t>>=1)
	{
		if(k>tra[t+p])k-=tra[t+p],p+=t;
	}return p+1; 
}
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),q.push((pii){a[i],i});
	scanf("%d",&m);
	for(i=1;i<=n;i++)
		add(i,1);
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y),vt[x].push_back(i);
	}
	for(i=n;i;i--)
	{
		for(ii=0;ii<v[i].size();ii++)
		{
			int t=locate(v[i][ii]);
			ans[vt[i][ii]]=a[t];
		}
		int t=q.top().t;
		add(t,-1),q.pop();
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}