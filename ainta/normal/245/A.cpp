#include<stdio.h>
int n,i,a,b,c,d,p,q,t;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&t,&p,&q);
		if(t==1)a+=10,c+=p;
		else b+=10,d+=p;
	}
	if(c*2>=a)printf("LIVE\n");else printf("DEAD\n");
	if(d*2>=b)printf("LIVE\n");else printf("DEAD\n");
}