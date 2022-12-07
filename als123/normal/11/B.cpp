#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if (n<0) n=-n;
	int sum=0;
	for (int u=0;;u++)
	{
		sum+=u;
		if (sum>=n&&(n-sum)%2==0)
		{
			printf("%d\n",u);
			break;
		}
	}
	return 0;
}