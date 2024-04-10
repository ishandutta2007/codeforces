#include <iostream>
using namespace std;
int main()
{
	int n,cur=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a>cur)
		{
			printf("%d",i+1);
			return 0;
		}
		if (a==cur)
		cur++;
	}
	printf("-1");
}