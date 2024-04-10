#include <cstdio>

int main()
{
	int n, k;
	scanf ("%i %i", &n, &k);

	if (k > n)
	{
		printf ("-1\n");
		return 0;
	}

	if (k == 1)
	{
		printf ("%s\n", n == 1 ? "a" : "-1");
		return 0;
	}

	for (int i = 0; i < n - k + 2; i++)
		printf ("%c", i % 2 == 0 ? 'a' : 'b');
	for (int i = 0; i < k - 2; i++)
		printf ("%c", 'a' + i + 2);
	printf ("\n");

	return 0;
}