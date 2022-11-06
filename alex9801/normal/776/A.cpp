#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr1[100];
char arr2[100];
char tmp[100];
char tmp2[100];

int main()
{
	int n, i, j;
	scanf("%s%s%d", arr1, arr2, &n);
	printf("%s %s\n", arr1, arr2);

	for(i = 0; i<n; i++)
	{
		scanf("%s%s", tmp, tmp2);

		if(strcmp(arr1, tmp) == 0)
			strcpy(arr1, tmp2);
		else
			strcpy(arr2, tmp2);

		printf("%s %s\n", arr1, arr2);
	}
	return 0;
}