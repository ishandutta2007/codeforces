#include<cstdio>
char str[1111111];
int n,m;
int main()
{
	scanf("%d%d%s",&n,&m,str+1);
	register int i,ii;
	long long ans=0;
	for(i=1;i<=n;i++)if(str[i]!=str[i-1])ans+=n*1ll*m-n;
	for(i=1;i<=n;)
	{
		for(ii=i;;ii++)
		{
			if(str[ii]==str[ii+1]||ii==n)break;
			if(ii!=i)if(str[ii+1]!=str[ii-1])break;
		}int d=ii-i;
		ans-=(d*1ll*(d+1))>>1,i=ii;
		if(!d)i++;
	}printf("%lld\n",ans);
}
/*
Please don't let me down.
*/