#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 105;
bool taken[maxN][maxN];

int main()
{
	int numQueries, size;
	scanf ("%i %i", &numQueries, &size);

	int xCenter = (size + 1) / 2, yCenter = (size + 1) / 2;

	for (int i = 0; i < numQueries; i++)
	{
		int M;
		scanf ("%i", &M);

		int xc, yc, cost = -1;

		for (int x = 0; x < size; x++)
			for (int y = 0; y < size - M + 1; y++)
			{
				int theCost = 0;

				bool ok = true;
				for (int t = 0; t < M; t++)
					if (taken[x][y + t])
					{
						ok = false;
						break;
					}
					else theCost += abs (x + 1 - xCenter) + abs (y + t + 1 - yCenter);

				if (!ok) continue;

				if (cost == -1 || theCost <= cost)
				{
					if (theCost == cost)
					{
						if (x > xc) continue;
						if (x == xc && y > yc) continue;
					}

					cost = theCost;
					xc = x;
					yc = y;
				}
			}

		if (cost == -1) { printf ("%i\n", -1); continue; }

		for (int t = 0; t < M; t++)
			taken[xc][yc + t] = true;

		printf ("%i %i %i\n", xc + 1, yc + 1, yc + M);
	}

	return 0;
}