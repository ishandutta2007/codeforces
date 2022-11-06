#include <stdio.h>
#include <string.h>
#include <algorithm>

char arr[100] = "fedabc";

int main()
{
	long long n, x, i;
	char c;
	scanf("%lld%c", &n, &c);

	n--;

	x = n/4*16;

	if(n%4%2==1)
		x += 7;

	for(i = 0;; i++)
	{
		if(c==arr[i])
		{
			x += i+1;
			break;
		}
	}

	printf("%lld", x);
	return 0;
}