#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d;

int main()
{
	scanf("%d", &t);
	for(int i=0; i<t; ++i)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if((a==c && b+d==a) || (a==d && c+b==a) || (b==c && a+d==b) || (b==d && a+c==b))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}