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
int n;
char s[1111111];
ll a[1111111];
void exec()
{
	register int i,ii,iii;
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	if(x==y&&x==z)
	{
		for(i=1;i<=x;i++)putchar('1');
		putchar(' ');
		for(i=1;i<=x;i++)putchar('1');
		puts("");
		return;
	}
	for(i=1;i<=x-z+1;i++)putchar('1');
	for(i=1;i<z;i++)putchar('0');
	putchar(' ');
	putchar('1');
	for(i=1;i<y;i++)putchar('0');
	puts("");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}