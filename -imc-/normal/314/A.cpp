#include <cstdio>

using namespace std;

const int maxN = 200005;

int main()
{
	int n, k;
	scanf ("%i %i", &n, &k);

	long long ratingSum = 0;
	int nonSkipped = 0;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf ("%i", &a);

		long long delta = ratingSum - a * (long long)(n - (i - nonSkipped) - (nonSkipped + 1)) * nonSkipped;

		//printf ("wtf %i\n", n - (i - nonSkipped) - (i + 1));
		//printf ("Rating sum %lld, n %i i %i nonSkipped %i\n", ratingSum, n, i, nonSkipped);
		//printf ("Delta %i: %i\n", i + 1, (int)delta);

		if (delta < k)
		{
			printf ("%i\n", i + 1);
		}
		else
		{
			ratingSum += a * nonSkipped;
			nonSkipped++;
		}
	}

	return 0;
}