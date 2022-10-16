#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
#define lowbit(x) (x&(-x))
int n;
ll x,y;
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
void exec()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
	{
		ll a;
		scanf("%lld",&a);
		ll t=i&1,r=a>>1,s=a-r;
		if(t)x+=r,y+=s;
		else y+=r,x+=s;
	}printf("%lld\n",min(x,y));
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/