#include <stdio.h>

int main()
{
	int n,t,tmp,i;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		tmp=86400-tmp;
		t-=tmp;
		if(t<=0) break;
	}
	printf("%d\n",i);
}