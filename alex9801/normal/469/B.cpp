#include <stdio.h>

bool chk1[2001];
bool chk2[2001];

int main()
{
	int a,b,p,q,l,r,s=0,i,j;
	scanf("%d%d%d%d",&p,&q,&l,&r);
	for(i=0;i<p;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=a;j<=b;j++)
			chk1[j]=1;
	}
	for(i=0;i<q;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=a;j<=b;j++)
			chk2[j]=1;
	}
	for(i=0;i<l;i++)
	{
		for(j=2000;j>0;j--)
			chk2[j]=chk2[j-1];
		chk2[0]=0;
	}
	for(i=l;i<=r;i++)
	{
		for(j=0;j<=2000;j++)
		{
			if(chk1[j]&&chk2[j])
			{
				s++;
				break;
			}
		}
		for(j=2000;j>0;j--)
			chk2[j]=chk2[j-1];
		chk2[0]=0;
	}
	printf("%d",s);
	return 0;
}