#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int first, second;

void solve (int max, int min)
{
	first = second = 0;

	if (min == 0)
	{
		first = max - 1;
		return;
	}

	int type = 1, turn = 1;
	min--;

	while (true)
	{
		if (turn == 1)
		{
			if (type == 1)
			{
				if (max == 0)
				{
					first += min;
					return;
				}

				second++;
				max--;
				type = 0;
			}
			else
			{
				if (min == 0)
				{
					first += max;
					return;
				}

				second++;
				min--;
				type = 1;
			}
		}
		else
		{
			if (type == 0)
			{
				if (max == 0)
				{
					first += min > 0 ? min - 1 : 0;
					if (min)
						second++;
					return;
				}

				first++;
				max--;
			}
			else
			{
				if (min == 0)
				{
					first += max > 0 ? max - 1 : 0;
					if (max)
						second++;
					return;
				}

				first++;
				min--;
			}
		}

		turn = turn ? 0 : 1;
	}
}

int main()
{
	int n, m;
	scanf ("%i %i", &n, &m);

	if (n < m)
		std::swap (n, m);

	solve (n, m);
	int f2 = first, s2 = second;
	solve (m, n);

	if (f2 > first)
	{
		first = f2;
		second = s2;
	}

	printf ("%i %i\n", first, second);

	return 0;
}