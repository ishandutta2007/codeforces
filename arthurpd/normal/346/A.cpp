#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b,  a % b);
}

int main(void)
{
	int n, mx = 0, gc = 0, a;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		mx = std::max(mx, a), gc = gcd(a, gc);
	}
	printf("%s\n", ((mx/gc - n) % 2) == 1 ? "Alice" : "Bob");
}