#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

int main()
{
	int x = 0;
	scanf ("%d", &x);
	if (x < 0) x *= -1;

	int tn = (-1 + sqrt (1 + 8.0 * x)) / 2;

	for (int n = tn - 8; n < tn + 8; n++)
	{
		if (n < 0) continue;
		long long maxCan = n * (long long)(n + 1) / 2;
		if (maxCan < x) continue;
		if (maxCan % 2 != x % 2) continue;

		printf ("%d\n", n);
		return 0;
	}

	assert (!"Not found");

	return 0;
}