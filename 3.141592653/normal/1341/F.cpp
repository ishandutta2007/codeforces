#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstdlib>
#include<queue>
using std::queue;
using std::priority_queue;
#include<cmath>
typedef long long ll;
typedef double db;
#define inlien inline
#define retrun return
#define cpnst const
int n;
char s[1111111];
ll a[1111111];
vector<int>v[1111111];
ll Max=0;
int s1[1111111],s2[1111111],top;
void push(int x,int y)
{s1[++top]=x,s2[top]=y;}
void dfs(int p,int l,int f=0)
{
	int ff=l;push(p,l);
	if(l==Max)
		{
			int t=v[p].size();
			l-=t,push(p,l);
		}
	for(auto g:v[p])
	{
		if(g==f)continue;
		dfs(g,l+1,p),l++,push(p,l);
		if((p^1)&&l==Max)
		{
			int t=v[p].size();
			l-=t,push(p,l);
		}
	}if(p!=1)
	{
		if(l>ff-1)
		{
			l=ff-1;push(p,l);
		}
	}
}
void exec()
{
	register int i,ii,iii;
	scanf("%d",&n);if(n==1){puts("1\n1 0");return;}
	for(i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}for(i=1;i<=n;i++)if(v[i].size()>Max)Max=v[i].size();
	dfs(1,0);
  printf("%d\n",top);
  for(i=1;i<=top;i++)printf("%d %d\n",s1[i],s2[i]);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}