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
char s[1111111];
ll a[1111111];
ll F[1111111];
ll S(ll nn,ll kk)
{
	register int i;
	ll ret=0;
	for(i=0;i<=kk;i++)ret+=F[nn+i];
	return ret;
}
ll G(ll nn){return nn?G(nn/10)+(nn%10):0;}
ll T(ll nn,ll kk)
{
	ll ret=0;
	register int i;
	for(i=0;i<=kk;i++)ret+=G(nn+i);
	return ret;
}
int n,k;
int SS[111111][11];
int v[1111];
void exec()
{
	register ll i,ii,iii;
	scanf("%d%d",&n,&k);
	for(i=0;i<100000;i++)
		if(SS[i][k]==n)return(void)printf("%lld\n",i);
	for(i=100000;i<1e18;i*=10)
		for(ii=i;ii<10*i;ii+=i)
		{
			for(iii=ii-200;iii<ii;iii++)v[ii-iii]=G(iii);
			for(iii=200;iii;iii--)v[iii]+=v[iii+1];
			for(iii=1;iii<=200;iii++)v[iii]-=v[iii+k+1];
			for(iii=ii-200;iii<ii-k;iii++)
				if(v[ii-k-iii]==n)return(void)printf("%lld\n",iii);
		}
	puts("-1");
}
int main()
{
	int T=1;
	register int i,ii;
	for(i=1;i<=100010;i++)F[i]=F[i/10]+(i%10);
	for(i=0;i<100000;i++)
		for(ii=0;ii<10;ii++)
			SS[i][ii]=S(i,ii);
	scanf("%d",&T);
	while(T--)exec();
}