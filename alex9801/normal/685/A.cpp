#include <stdio.h>
#include <string.h>
#include <algorithm>

int arr[7];
int tmp[7];

int main()
{
	bool u;
	int n, m, t, a = 0, b = 0, r = 0, i;
	scanf("%d%d", &n, &m);

	t = n-1;
	while(t)
	{
		t /= 7;
		a++;
	}
	if(n==1)
		a = 1;

	t = m-1;
	while(t)
	{
		t /= 7;
		b++;
	}
	if(m==1)
		b = 1;

	for(i = 0; i<7; i++)
		arr[i] = i;

	memset(tmp, -1, sizeof(tmp));

	if(a+b>7)
	{
		printf("0");
		return 0;
	}

	do
	{
		u = 0;
		for(i = 0; i<a+b; i++)
		{
			if(arr[i]!=tmp[i])
			{
				u = 1;
				break;
			}
		}
		if(!u)
			continue;

		for(i = 0; i<a+b; i++)
			tmp[i] = arr[i];

		t = 0;
		for(i = 0; i<a; i++)
		{
			t *= 7;
			t += arr[i];
		}
		if(t>=n)
			continue;

		t = 0;
		for(i = a; i<a+b; i++)
		{
			t *= 7;
			t += arr[i];
		}
		if(t>=m)
			continue;
		r++;
	}
	while(std::next_permutation(arr, arr+7));

	printf("%d", r);
	return 0;
}