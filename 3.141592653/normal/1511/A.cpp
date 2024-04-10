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
	scanf("%d",&n);
	
	int ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(a[i]&1)ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}