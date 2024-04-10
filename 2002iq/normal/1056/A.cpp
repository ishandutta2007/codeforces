#include <iostream>
using namespace std;
int cnt[105];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		while (x--)
		{
			int a;
			scanf("%d",&a);
			cnt[a]++;
		}
	}
	for (int i=1;i<=100;i++)
	{
		if (cnt[i]==n)
		printf("%d ",i);
	}
}