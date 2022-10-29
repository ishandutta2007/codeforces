#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

char bar[1123456];

int
main(void)
{
	int pivot, n;
	scanf(" %s", bar);
	n = strlen(bar);
	long long left = 0, right = 0;
	for(int i = 0; i < n; i++)
		if(bar[i] == '^')
			pivot = i;
	for(int i = 0; i < pivot; i++)
		if(bar[i] != '=')
			left += (pivot-i) * (long long) (bar[i]-'0');
	for(int i = pivot+1; i < n; i++)
		if(bar[i] != '=')
			right += (i-pivot) * (long long) (bar[i]-'0');
	if(left > right)
		printf("left\n");
	else if(right > left)
		printf("right\n");
	else
		printf("balance\n");
	return 0;
}