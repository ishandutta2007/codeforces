#include<cstdio>
#include<cstring>
const int N=200005;
int n;
int a,b;
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		if (x==1) a++;
		else b++;
	}
	if (b>=a) printf("%d\n",a);
	else
	{
		int c=a-b;//1
		printf("%d",b+c/3); 
	}
	return 0;
}