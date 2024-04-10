#include<bits/stdc++.h>
using namespace std;
inline int sqr(int x)
{
	return x*x;
}
int main()
{
	int t,x;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&x);
		if (x%2==1)
		{
			puts("NO");
			continue;;
		}
		x/=2;
		if (sqr((int)(sqrt(x)+1e-8))==x)
		{
			puts("YES");
			continue;
		}
		if (x%2==1)
		{
			puts("NO");
			continue;;
		}
		x/=2;
		if (sqr((int)(sqrt(x)+1e-8))==x)
		{
			puts("YES");
			continue;
		}
		puts("NO");
	}
	return 0;
}