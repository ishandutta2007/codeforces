#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=1000005;
LL n;
LL h[N];
void print (LL x,LL i)
{
//	printf("ans:%lld %lld\n",x,i);
	for (LL u=1;u<=n;u++)
	{
		printf("%lld ",x);
		if (u!=i) x++;
	}
}
int main()
{
	scanf("%lld",&n);
	for (LL u=1;u<=n;u++) scanf("%lld",&h[u]);
	if (n==1)	{printf("%lld\n",h[1]);return 0;}
	LL x=(h[n]+h[n-1])/2,i;
	if ((h[n]-h[n-1])&1)	i=n;
	else i=n-1;
//	printf("%lld %lld\n",x,i);
	for (LL u=n-2;u>=1;u--)
	{
		if (i!=n)
		{
			LL tot=i-(u+1);
			if (h[u]+tot+1<=x)
				h[u]=h[u]+tot;
			else
			{
				i=i-((x-1)-h[u]);
				x--;//printf("A:%lld %lld %lld\n",u,x,i);
				continue;
			}
			//printf("YES:%lld %lld\n",h[u],x);
			if (h[u]<=x-2)	{x--;h[u]++;i=n;}
			else {x=h[u];i=u+1;continue;}
		}
		LL t=n-u;
		LL a=(x-h[u])/(t+1);
		h[u]=h[u]+t*a;x-=a;
		
	//	while (h[u]+t<=x-1)	{h[u]+=t;x--;}
		if (h[u]==x) {i=u;continue;}
		LL need=(x-1)-h[u];
		i=n-need;x--;
		//printf("%lld %lld\n",x,i);
	}
	print(x,i);
	return 0;
}