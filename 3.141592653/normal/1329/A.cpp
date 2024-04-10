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
int n,m;
char s[1111111];
ll a[1111111];
bool valid()
{
	register int i;
	long long s=0;
	for(i=1;i<=m;i++)s+=a[i];
	if(s<n)return 0;
	for(i=m;i;i--)if(a[i]+i-1>n)return 0;
	return 1;
}
ll ans[1111111];
void exec()
{
	register int i,ii,iii;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)scanf("%lld",a+i);
	if(!valid()){puts("-1");return;}
	ll g=n+1;
	for(i=m;i;i--)
	{
		g-=a[i];
		if(g<i)g=i;
		ans[i]=g;
	}for(i=1;i<=m;i++)printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}