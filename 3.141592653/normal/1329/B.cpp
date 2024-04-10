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
ll d,m;
char s[1111111];
ll a[1111111];
ll dp[111][111];
void exec()
{
	register int i,ii,iii;
	scanf("%lld%lld",&d,&m);
	if(d==1)return(void)printf("%d\n",1%m);
	ll s=1,ans=0;
	for(i=1;i<=(d>>1);i<<=1)
	{
		//printf("%d\n",s);
		(ans+=s*i)%=m; 
		s=(ans+1)%m;
	}(ans+=s*(d-i+1))%=m;
	printf("%lld\n",ans);
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}