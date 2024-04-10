#include<cstdio>
using namespace std;
int T,a,b;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		a=a/2+1;
		printf("%d\n",b/a);
	}
}