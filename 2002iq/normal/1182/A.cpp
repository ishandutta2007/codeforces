#include <iostream>
using namespace std;
int main()
{
	int n,ans=1;
	scanf("%d",&n);
	if (n%2)
	{
		printf("0");
		return 0;
	}
	for (int i=0;i<n/2;i++)
	ans=(ans*2);
	printf("%d",ans);
}