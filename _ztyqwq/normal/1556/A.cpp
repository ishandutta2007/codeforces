#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if((a + b) & 1)
			printf("-1\n");
		else if(a == 0 && b == 0)
			printf("0\n");
		else if(a == b || a == -b)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}