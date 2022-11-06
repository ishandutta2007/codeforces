#include <stdio.h>

int main()
{
	int h, m, a;
	scanf("%d:%d %d", &h, &m, &a);

	m += a;
	printf("%02d:%02d", (h+m/60)%24, m%60);
}