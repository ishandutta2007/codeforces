#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,a[111111],rk[111111],ct[111111];
char c[1111][1111];
int main()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",a+i),ct[a[i]]++;
	for(i=n;i;i--)ct[i]+=ct[i+1];
	for(i=1;i<=n;i++)
	{
		rk[i]=ct[a[i]]--;
		int cs=a[i];
		for(ii=rk[i]+1;;)
		{
			if(cs)c[ii][i]='1',cs--;
			else c[ii][i]='0';
			ii=ii%(n+1)+1;
			if(ii==rk[i]+1)break;
		}
	}printf("%d\n",n+1);
	for(i=1;i<=n+1;i++)puts(c[i]+1);
}
/*
Please don't let me down.
*/