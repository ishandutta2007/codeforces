#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d", k*(n/k+1));
	return 0;
}