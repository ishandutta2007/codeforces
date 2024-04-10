#include<cstdio>
int n;
int a,b,c;
int d;
int mymin (int x,int y){return x<y?x:y;}
int mymax (int x,int y){return x>y?x:y;}
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	d=mymin(c,mymin(a,b));
	if (n==1) {printf("0");return 0;}
	if (d==a||d==b)// 
		printf("%d\n",d*(n-1));
	else
	{
		printf("%d\n",mymin(a,b)+d*(n-2));
	}
	return 0;
}