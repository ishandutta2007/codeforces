#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h[7][7];
int a[7] = {1,2,3,4,5,0};

int count()
{
	int retv = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = i; j < 5; j+= 2)
		{
			retv += h[a[j]][a[j+1]] + h[a[j+1]][a[j]];
		}
	}
	return retv;
}

int
main(void)
{
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 5; j++)
			scanf("%d", &h[i][j]);
	
	int ans = 0;
	do
	{
		ans = max(ans, count());
	}
	while(next_permutation(a, a+5));	
	
	printf("%d\n", ans);
	
	return 0;
}