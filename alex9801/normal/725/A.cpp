#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[200010];

int main()
{
	int n, c = 0, i;
	scanf("%d%s", &n, arr);

	for(i = 0; i<n; i++)
	{
		if(arr[i]=='>')
			break;
		c++;
	}

	for(i = n-1; i>=0; i--)
	{
		if(arr[i]=='<')
			break;
		c++;
	}

	printf("%d", c);

	return 0;
}