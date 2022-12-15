#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	b/=2; c/=4;
	int min;
	if(a<b) min=a;
	else min=b;
	if(min>c)min=c;
	printf("%d\n",min*7);
	return 0;
}