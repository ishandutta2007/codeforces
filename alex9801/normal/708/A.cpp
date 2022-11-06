#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[100010];

int main()
{
	bool u = 0, v = 0;
	int l, i;
	scanf("%s", arr);

	l = strlen(arr);
	for(i = 0; i<l; i++)
	{
		if(arr[i] != 'a' && u==0)
			u = 1;

		if(u==1)
		{
			if(arr[i] != 'a')
			{
				arr[i]--;
				v = 1;
			}
			else
				break;
		}
	}

	if(v == 0)
		arr[l-1] = 'z';
	printf("%s", arr);
	return 0;
}