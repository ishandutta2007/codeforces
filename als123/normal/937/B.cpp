#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int p,y;
bool check (int x)
{
	if (x%2==0) return false;
	for (int u=3;u*u<=x&&u<=p;u+=2)
		if (x%u==0) return false;
	return true;
}
int main()
{
	scanf("%d%d",&p,&y);
	while (y>p)
	{
		if (check(y))
		{
			printf("%d\n",y);
			return 0;
		}
		y--;
	}
	printf("-1");
	return 0;
}