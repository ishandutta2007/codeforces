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
ll a[1111111],b[1111111];
struct pii
{int x,y;}p[1111111],q[1111111];
bool operator<(cpnst pii x,cpnst pii y)
{return(x.x^y.x)?x.x<y.x:x.y<y.y;}
void exec()
{
	register int i,ii,iii;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(i=1;i<=n;i++)
		scanf("%lld",b+i);
	for(i=1;i<=n;i++)p[i]=pii{a[i],a[n-i+1]};
	for(i=1;i<=n;i++)q[i]=pii{b[i],b[n-i+1]};
	sort(p+1,p+n+1);
	sort(q+1,q+n+1);
	for(i=1;i<=n;i++)
		if(p[i].x!=q[i].x||p[i].y!=q[i].y)
			{puts("No");return;}
	puts("Yes");
	return;
	
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}