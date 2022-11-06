#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[100];
char s[1000];

int main()
{
	int n, c, i, j;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%d ", &arr[i]);
	for(i = 0; i<n; i++)
	{
		c = 0;
		fgets(s, 1000, stdin);
		for(j = 0; s[j]; j++)
		{
			if(s[j] == 'a' ||s[j] == 'e' ||s[j] == 'i' ||s[j] == 'o' ||s[j] == 'u' ||s[j] == 'y')
				c++;
		}
		if(arr[i] != c)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}