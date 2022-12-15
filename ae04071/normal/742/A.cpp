#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if(n == 0) printf("1\n");
	else {
		if(n%4 == 1) printf("8\n");
		else if(n%4==2) printf("4\n");
		else if(n%4==3) printf("2\n");
		else printf("6\n");
	}
	return 0;
}