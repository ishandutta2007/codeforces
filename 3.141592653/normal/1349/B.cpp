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
int n,k;
char s[1111111];
ll a[1111111];
int c[1111111];
void exec()
{
	register int i,ii,iii;
	bool f=0;
	ll mns=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)scanf("%lld",a+i);
	c[n+1]=0;
	if(n==1)
	{
		if(a[1]==k)goto Yep;
		else goto Nop;
	}for(i=1;i<=n;i++)
		if(a[i]==k)f=1;
	if(!f)goto Nop;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=k)c[i]=1;
		else c[i]=-1;
	}for(i=1;i<=n-1;i++)
		if(c[i]+c[i+1]+c[i+2]>0)
			goto Yep;
	goto Nop;
	Yep:
	puts("yes");
	return;
	Nop:
	puts("no");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}