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
char s[3111111];
ll a[2222222],b[2222222];
void exec()
{
	register int i,ii,iii;
	
	scanf("%d",&n);
	ll as=0,bs=0;
	for(i=1;i<=n;i++)scanf("%lld",a+i),a[n+i]=a[i],as+=a[i];
	for(i=1;i<=n;i++)scanf("%lld",b+i),b[n+i]=b[i],bs+=b[i];
	for(i=1;i<=n;i++)std::swap(a[i],a[(n<<1)-i]);
	for(i=1;i<=n;i++)std::swap(b[i],b[(n<<1)-i]);
	
	if(as>bs)return (void)puts("NO");
	ll GG=0;
	for(i=1;i<(n<<1);i++)
	{
		GG=GG-a[i]+b[i];
		if(GG>0)GG=0;
		if(GG+b[i+1]<0)return (void)puts("NO");
	}
	puts("YES");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}