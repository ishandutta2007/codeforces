#include <bits/stdc++.h>
using namespace std;
int n;
int a[500000];
int am[500010];
int greatest, nGreatest;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		am[a[i]]++;
	}
	for (int i = 0; i <= 500000; i++)
	{
		if (am[i] % 2)
		{
			printf("Conan\n");
			return 0;
		}
	}
	printf("Agasa\n");
}