#include <bits/stdc++.h>
using namespace std;
char a, b;
int main()
{
	scanf(" %c%c", &a, &b);
	for (int i = 0; i < 5; i++)
	{
		char c, d;
		scanf(" %c%c", &c, &d);
		if (a == c || b == d) 
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}