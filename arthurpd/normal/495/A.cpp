#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int k[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int
main(void)
{
	int n;
	scanf("%d", &n);
	int x = n/10, y = n%10;
	printf("%d\n", k[x]*k[y]);
}