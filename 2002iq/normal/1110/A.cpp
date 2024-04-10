#include <iostream>
using namespace std;
int main()
{
	int b,k,ans=0;
	scanf("%d%d",&b,&k);
	for (int i=1;i<k;i++)
	{
		int d;
		scanf("%d",&d);
		ans^=((d*b)%2);
	}
	int t;
	scanf("%d",&t);
	if ((ans+t)%2)
	printf("odd");
	else
	printf("even");
}