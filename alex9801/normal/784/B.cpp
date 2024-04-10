#include <stdio.h>
#include <string.h>
#include <algorithm>



int main()
{
	int a, r, t;
	scanf("%d", &a);

	if(a==0)
	{
		printf("1");
		return 0;
	}

	r = 0;
	while(a)
	{
		t = a%16;
		if(t == 10 || t == 13 || t == 9 || t == 4 || t == 6 || t == 0)
			r++;
		else if(t == 11 || t == 8)
			r += 2;
		a /= 16;
	}
	printf("%d", r);
	return 0;
}