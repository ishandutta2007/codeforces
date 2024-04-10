#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[200010];

int main()
{
	bool u = 0;
	int l, t, p = -1, c = -1, x, d, i;
	scanf("%d%d%s", &l, &t, arr+1);

	arr[0] = '0';

	for(i = l; i>0; i--)
	{
		if(arr[i]=='.')
		{
			d = i;
			break;
		}

		if(arr[i]>='5')
		{
			p = i;
			u = 1;
			c = 0;
		}
		else if(arr[i]=='4' && u)
			c++;
		else
			u = 0;

	}

	if(p==-1)
	{
		printf("%s", arr+1);
		return 0;
	}

	arr[d] = '0';


	x = std::min(t-1, c);

	arr[p-x] = '\0';
	arr[p-x-1]++;

	for(i = p-x-1; i>=d; i--)
	{
		if(arr[i]>'9')
		{
			arr[i] -= 10;
			arr[i-1]++;
		}
		else
			break;
	}

	if(arr[d] != '0')
	{
		arr[d-1]++;
		for(i = d-1; i>0; i--)
		{
			if(arr[i]>'9')
			{
				arr[i] -= 10;
				arr[i-1]++;
			}
			else
				break;
		}
	}

	arr[d] = '.';

	for(i = p-x-1; i>=0; i--)
	{
		if(arr[i]=='0')
			arr[i] = '\0';
		else
			break;
	}

	if(arr[d+1]=='\0')
		arr[d] = '\0';

	if(arr[0]=='0')
		printf("%s", arr+1);
	else
		printf("%s", arr);


	return 0;
}