#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	puts(n & 1 ? "Ehab" : "Mahmoud");
	return 0;
}