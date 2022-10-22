#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long gcd (long long a, long long b)
{
	while (a && b)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}

	return a + b;
}

int main()
{
	int n;
	scanf ("%d", &n);

	vector <int> a;
	vector <int> times (n);

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf ("%d", &x);
		a.push_back (x);
	}

	sort (a.begin(), a.end(), greater <int>());

	long long xsum = 0;

	for (int i = 0; i < n; i++)
	{
		long long weight = n % 2 == 0 ? (-1 + (n / 2 - i) * 4) : (1 + (n / 2 - i) * 4);
		//printf ("%lld\n", weight);
		xsum += weight * a[i];
	}

	//cout << xsum << endl;

	long long xdiv = gcd (xsum, n);
	long long xn = n;
	xn /= xdiv;
	xsum /= xdiv;

	cout << xsum << " " << xn << endl;
	return 0;

	vector <int> order (n);
	for (int i = 0; i < n; i++) order[i] = i;

	long long sum = 0, nWays = 0;

	do
	{
		for (int i = 0; i < n; i++)
		{
			sum += abs (a[order[i]] - (i ? a[order[i - 1]] : 0));
			if (!i)
				times[order[i]]++;
			else if (a[order[i]] > a[order[i - 1]])
			{
				times[order[i]]++;
				times[order[i - 1]]--;
			}
			else
			{
				times[order[i]]--;
				times[order[i - 1]]++;
			}
		}

		nWays++;
	}
	while (next_permutation (order.begin(), order.end()));

	printf ("Sum: %lld, nWays: %lld\n", sum, nWays);

	long long div = gcd (sum, nWays);
	sum /= div;
	nWays /= div;
	printf ("Answer %lld %lld\n", sum, nWays);

	printf ("delta %d\n", abs (times[1] - times[0]));

	for (int i = 0; i < n; i++)
		printf ("%d\n", times[i]);

	return 0;
}