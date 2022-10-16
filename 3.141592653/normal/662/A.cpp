#include<cstdio>
typedef long long ll;
ll bas[66],a,b,sum=0;
int n,tot;
inline void insert(ll x)
{
	for(register int i=60;~i;i--)
		if(x&(1ll<<i))
		{
			if(!bas[i]){bas[i]=x;return;}
			x^=bas[i];
		}
}
int main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%I64d%I64d",&a,&b),sum^=a,insert(a^b);
	for(i=60;~i;i--)
	{
		if(sum&(1ll<<i))sum^=bas[i];
		tot+=bas[i]>0;
	}if(sum)puts("1/1");
	else printf("%I64d/%I64d\n",(1ll<<tot)-1,(1ll<<tot));
}