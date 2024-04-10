#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf ("%d", &n);

	vector <int> numbers (n);

	for (int i = 0; i < n; i++)
		scanf ("%d", &numbers[i]);

	sort (numbers.begin(), numbers.end());
	numbers.erase (unique (numbers.begin(), numbers.end()), numbers.end());

	int a, b;
	scanf ("%d %d", &a, &b);

	int nOps = 0;

	while (a != b)
	{
		int can = a - 1;
		for (int i = numbers.size() - 1; i >= 0; i--)
		{
			int bringTo = a / numbers[i] * numbers[i];
			//printf ("Can %d to %d via %d\n", a, bringTo, numbers[i]);
			if (bringTo < b)
			{
				swap (numbers[i], numbers.back());
				numbers.pop_back();
				continue;
			}

			can = min (bringTo, can);
		}
		a = can;
		//printf ("now a is %d\n", can);
		nOps++;
	}

	printf ("%d\n", (int )nOps);

	return 0;
}