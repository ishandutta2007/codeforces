#include<bits/stdc++.h>
using namespace std;

int n, s;

int main()
{
	scanf("%d%d", &n, &s);
	if (n * 2 > s)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1; i < n; i++) printf("%d ", 2);
	printf("%d\n", s - n * 2 + 2);
	printf("%d\n", 1);
	return 0;
}