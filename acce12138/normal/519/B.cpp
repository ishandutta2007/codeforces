#include <bits/stdc++.h>
using namespace std;
int n,a;
int main()
{
	int t=0,tt=0,ttt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		t^=a;
	}
	for(int i=0;i<n-1;i++)
	{
		scanf("%d",&a);
		tt^=a;
	}
	for(int i=0;i<n-2;i++)
	{
		scanf("%d",&a);
		ttt^=a;
	}
	printf("%d\n%d\n",t^tt,tt^ttt);
	return 0;
}