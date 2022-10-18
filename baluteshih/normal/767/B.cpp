#include <stdio.h>

long long tmp,ts,tf,t,n,now,num[100000],max,maxn;

int main()
{
	int i,j;
	scanf("%lld%lld%lld%lld",&ts,&tf,&t,&n);
	for(i=0,now=ts;i<n;i++)
	{
		scanf("%lld",&num[i]);
		if(num[i]>now) break;
		else now = now+t;
	}
	if(now>tf-t)
	{
		for(j=1,now=ts+t;j<i;j++)
		{
			if(now>tf-t) break;
			else now = now+t;
			tmp=num[j]-num[0]-j*t;
			if(tmp>max) max=tmp,maxn=j;
		}
		printf("%lld\n",num[maxn]-1);
	}
	else printf("%lld\n",now);
}