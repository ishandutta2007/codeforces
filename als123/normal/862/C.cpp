#include<cstdio>
#include<cstring>
const int PW=1<<17;
int n,x;
int main()
{
	scanf("%d%d",&n,&x);
	if (n==2&&x==0)  
	{
		printf("No\n");
		return 0;
	}	
	printf("YES\n");
	if (n==1) printf("%d\n",x);
	else if (n==2) printf("%d %d\n",0,x);
	else
	{
		int y=0;
	 	for (int u=1;u<=n-3;u++) 
		{
			printf("%d ",u);
			y^=u;
		}
		if (x==y) printf("%d %d %d\n",PW,PW*2,PW*2+PW);
		else printf("%d %d %d\n",0,PW,PW^x^y);
	}
 	return 0;
}