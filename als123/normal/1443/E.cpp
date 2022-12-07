#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
const LL B=20;
LL JC[N];
LL n,q;
LL sum[N],a[N],b[N];
bool used[N];
void solve (LL m)
{
//	m--;
	LL t=min(n,B);
	for (LL u=1;u<=t+5;u++) used[u]=false;
	for (LL u=1;u<=t;u++)
	{
		LL x=t-u,t1=m/JC[x];m=m-t1*JC[x];
	//	printf("%lld %lld %lld %lld\n",u,t1);
		for (LL i=1;i<=t;i++)
		{
			if (used[i]==false)
			{
				if (t1==0)	{b[u]=i;used[i]=true;break;}
				else t1--;
			}
		}
	}
	LL o=n-t+1;
	for (LL u=o;u<=n;u++) a[u]=b[u-o+1]+o-1;
	for (LL u=o;u<=n;u++) sum[u]=sum[u-1]+a[u];
	/*printf("%lld %lld\n",t,o);
	for (LL u=1;u<=n;u++) printf("%lld ",b[u]);printf("\n");
	for (LL u=1;u<=n;u++) printf("%lld ",a[u]);printf("\n");*/
}
int main()
{
	JC[0]=1;
	for (LL u=1;u<=B;u++) JC[u]=JC[u-1]*u;
	scanf("%lld%lld",&n,&q);
	for (LL u=1;u<=n;u++) a[u]=u;
	for (LL i=1;i<=n;i++) sum[i]=sum[i-1]+i;
	LL m=0;
	while (q--)
	{
		LL op;
		scanf("%lld",&op);
		if (op==1)
		{
			LL l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",sum[r]-sum[l-1]);
		}
		else
		{
			LL x;
			scanf("%lld",&x);
			m=m+x;
			solve(m);
		}
	}
	return 0;
}