#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n + 1; i++)
		printf("%d %d\n", 1000 + i * 2 / 3, 1000 + i * 2 % 3);
	return 0;
}