#include <bits/stdc++.h>
using namespace std;
int coun[200];
int amount;
int num1, num2;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		coun[a]++;
	}
	for (int i = 0; i < 200; i++)
	{
		if (coun[i])
		{
			if (amount == 2 || coun[i] != n/2)
			{
				printf("NO\n");
				return 0;
			}
			if (amount == 0) num1 = i;
			if (amount == 1) num2 = i;
			amount++;
		}
	}
	printf("YES\n%d %d\n", num1, num2);
}