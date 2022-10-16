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
void exec()
{
	register int i,ii,iii;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	a[n+1]=0;
	int mx=n,ls=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]<a[i+1])
			if(a[i]!=a[i+1]-1)
				return(void)puts("No");
	}puts("Yes");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}