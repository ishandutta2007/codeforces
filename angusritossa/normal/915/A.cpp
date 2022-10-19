#include <bits/stdc++.h>
using namespace std;
int mn = 999999999;
int n, a;
int main()
{
	scanf("%d%d", &n, &a);
	for (int i = 0; i < n; i++)
	{
		int b;
		scanf("%d", &b);
		if (!(a % b))
		{
			mn = min(mn, a/b);
		}
	}
	printf("%d\n", mn);
}