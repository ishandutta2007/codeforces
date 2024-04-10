#include <stdio.h>
#include <algorithm>

char arr[51];

int main()
{
	int r = 0, i;
	scanf("%s", arr);

	for(i = 0; arr[i]; i++)
	{
		if('A'<=arr[i] && arr[i]<='Z')
			r += arr[i]-'A'+1;
		else if('a'<=arr[i] && arr[i]<='z')
			r -= arr[i]-'a'+1;
	}
	printf("%d", r);
	return 0;
}