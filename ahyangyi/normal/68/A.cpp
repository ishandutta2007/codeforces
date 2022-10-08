#include <stdio.h>

int p1, p2, p3, p4, a, b;

int test1 (int a, int p1, int p2, int p3, int p4)
{
	return a % p1 % p2 % p3 % p4 == a;
}

int test2 (int a, int p1, int p2, int p3, int p4)
{
	return 
		test1(a, p1, p2, p3, p4) +
		test1(a, p1, p2, p4, p3);
}

int test3 (int a, int p1, int p2, int p3, int p4)
{
	return 
		test2(a, p1, p2, p3, p4) +
		test2(a, p1, p3, p2, p4) +
		test2(a, p1, p4, p2, p3);
}

int test4 (int a, int p1, int p2, int p3, int p4)
{
	return 
		test3(a, p1, p2, p3, p4) +
		test3(a, p2, p1, p3, p4) +
		test3(a, p3, p2, p1, p4) +
		test3(a, p4, p2, p3, p1);
}

int main ()
{
	scanf ("%d%d%d%d%d%d", &p1, &p2, &p3, &p4, &a, &b);

	int ans = 0;

	for (int i = a; i <= b; i ++)
	{
		int count = 0;
		count += test4(i, p1, p2, p3, p4);

		if (count >= 7)
			ans ++;
	}

	printf ("%d\n", ans);

	return 0;
}