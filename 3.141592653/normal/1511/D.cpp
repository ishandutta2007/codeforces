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
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
int n,k,KP;
char s[1111111];
ll a[1111111];
char rgen[1111111];
int tot=0;
void gen(int dep=1)
{
	if(dep==k+1)return;
	rgen[++tot]=96+dep;
	if(dep!=k)rgen[++tot]=96+dep;
	for(register int i=dep+2;i<=k;i++)
	{
		rgen[++tot]=96+i;
		rgen[++tot]=96+dep;
	}
	gen(dep+1);
	rgen[++tot]=96+dep;
}
void exec()
{
	scanf("%d%d",&n,&k),KP=k*k;
	register int i,ii;
	gen();
	//puts(rgen+1);
	for(i=1;i<=n;i++)
		putchar(rgen[(i-1)%KP+1]);
	puts("");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}