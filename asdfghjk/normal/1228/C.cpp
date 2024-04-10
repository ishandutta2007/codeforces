#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int md=1000000007;
int x,i,ans=1;
ll n;
int pw(int a,ll b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
void work(int p)
{
	ll w,g;
	for(g=1,w=n;w;g*=p,w/=p)
		ans=1ll*ans*pw(g%md,w-w/p)%md;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%I64d",&x,&n);
	for(i=2;i*i<=x;++i)
		if(x%i==0)
		{
			work(i);
			while(x%i==0)
				x/=i;
		}
	if(x>1)
		work(x);
	printf("%d",ans);
	return 0;
}