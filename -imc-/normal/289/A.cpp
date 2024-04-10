#include <cstdio>

int main()
{
	int n, k;
	scanf ("%i %i", &n, &k);

	int length = 0;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf ("%i %i", &l, &r);
		length += r - l + 1;
	}

	printf ("%i\n", (k - length % k) % k);

	return 0;
}