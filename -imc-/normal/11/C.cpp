#include <cstdio>
#include <cassert>

using namespace std;

const int maxN = 300;
bool matrix[maxN][maxN];

int nRows, nColumns;

int leftStreak[maxN][maxN], downStreak[maxN][maxN];

int findRight()
{
	for (int y = 0; y < nRows; y++)
		for (int x = nColumns - 1; x >= 0; x--)
			leftStreak[x][y] = (x != nColumns - 1) ? (matrix[x][y] == matrix[x + 1][y] ? leftStreak[x + 1][y] + 1 : 1) : 1;

	for (int x = 0; x < nColumns; x++)
		for (int y = nRows - 1; y >= 0; y--)
			downStreak[x][y] = (y != nRows - 1) ? (matrix[x][y] == matrix[x][y + 1] ? downStreak[x][y + 1] + 1 : 1) : 1;

	int answer = 0;

	for (int x = 0; x < nColumns; x++)
		for (int y = 0; y < nRows; y++)
		{
			//printf ("%d %d: streaks %d %d\n", x, y, leftStreak[x][y], downStreak[x][y]);
			if (matrix[x][y])
			{
				int size = downStreak[x][y];
				if (size < 2) continue;

				if (leftStreak[x][y] != size) continue;
				if (downStreak[x + size - 1][y] != size) continue;
				if (leftStreak[x][y + size - 1] != size) continue;

				if (x && y && matrix[x - 1][y - 1]) continue;
				if (x && y + size < nRows && matrix[x - 1][y + size]) continue;
				if (x + size < nColumns && y && matrix[x + size][y - 1]) continue;
				if (x + size < nColumns && y + size < nRows && matrix[x + size][y + size]) continue;

				if (x && (matrix[x - 1][y] || downStreak[x - 1][y] < size)) continue;
				if (y && (matrix[x][y - 1] || leftStreak[x][y - 1] < size)) continue;
				if (x + size < nColumns && (matrix[x + size][y] || downStreak[x + size][y] < size)) continue;
				//printf ("preFound %d %d\n", x, y);
				if (y + size < nRows && (matrix[x][y + size] || leftStreak[x][y + size] < size)) continue;


				if (size > 2)
				{
					if (matrix[x + 1][y + 1] || leftStreak[x + 1][y + 1] != size - 2) continue;
					if (matrix[x + 1][y + 1] || downStreak[x + 1][y + 1] != size - 2) continue;
					if (matrix[x + 1][y + size - 2] || leftStreak[x + 1][y + size - 2] != size - 2) continue;
					if (matrix[x + size - 2][y + 1] || downStreak[x + size - 2][y + 1] != size - 2) continue;
				}

				answer++;
				//printf ("Found straight %d %d\n", x, y);
			}
		}

	return answer;
}

int plusStreak[maxN][maxN], rightStreak[maxN][maxN];

bool filled (int x, int y)
{
	if (x < 0 || y < 0 || x >= nColumns || y >= nRows) return false;
	//if (matrix[x][y])
	//printf ("check %d %d => fail\n", x, y);
	return matrix[x][y];
}

int findStupid()
{
	for (int y = nRows - 1; y >= 0; y--)
		for (int x = nColumns - 1; x >= 0; x--)
			rightStreak[x][y] = (x + 1 < nColumns && y + 1 < nRows) ? (matrix[x + 1][y + 1] == matrix[x][y] ? rightStreak[x + 1][y + 1] + 1 : 1) : 1;


	for (int y = nRows - 1; y >= 0; y--)
		for (int x = 0; x < nColumns; x++)
			plusStreak[x][y] = (x && y + 1 < nRows) ? (matrix[x - 1][y + 1] == matrix[x][y] ? plusStreak[x - 1][y + 1] + 1 : 1) : 1;

	/*printf ("\n");
	for (int y = 0; y < nRows; y++)
	{
		for (int x = 0; x < nColumns; x++)
			printf ("%d", plusStreak[x][y]);
		printf ("\n");
	}*/

	int answer = 0;

	for (int x = 0; x < nColumns; x++)
		for (int y = 0; y < nRows; y++)
			if (matrix[x][y])
			{
				int size = plusStreak[x][y];
				if (size != rightStreak[x][y]) continue;
				if (size < 2) continue;

				if (rightStreak[x - size + 1][y + size - 1] != size) continue;
				if (plusStreak[x + size - 1][y + size - 1] != size) continue;

				if (matrix[x - 1][y] || plusStreak[x - 1][y] < size - 1) continue;
				if (matrix[x + 1][y] || rightStreak[x + 1][y] < size - 1) continue;
				if (matrix[x - size + 1][y + size] || rightStreak[x - size + 1][y + size] < size - 1) continue;
				if (matrix[x + size - 1][y + size] || plusStreak[x + size - 1][y + size] < size - 1) continue;

				if (y && matrix[x][y - 1]) continue;
				if (x - size >= 0 && matrix[x - size][y + size - 1]) continue;
				if (x + size < nColumns && matrix[x + size][y + size - 1]) continue;
				if (y + size * 2 - 1 < nRows && matrix[x][y + size * 2 - 1]) continue;

				if (matrix[x][y + 1] || rightStreak[x][y + 1] < size - 1) continue;
				if (matrix[x][y + 1] || plusStreak[x][y + 1] < size - 1) continue;
				if (size > 2)
				{
					if (matrix[x + size - 2][y + size - 1] || plusStreak[x + size - 2][y + size - 1] < size - 1) continue;
					if (matrix[x - size + 2][y + size - 1] || rightStreak[x - size + 2][y + size - 1] < size - 1) continue;
				}
				//printf ("Diag maybe %d %d\n", x, y);

				for (int t = 0; t < size; t++)
				{
					if (filled (x - t - 1, y - 1 + t)) goto fail;
					if (filled (x + t + 1, y - 1 + t)) goto fail;
					if (filled (x - size + t, y + size + t)) goto fail;
					if (filled (x + size - t, y + size + t)) goto fail;

					if (t > 0 && t < size - 1 && filled (x - t + 1, y + 1 + t)) goto fail;
					if (t > 0 && t < size - 1 && filled (x + t - 1, y + 1 + t)) goto fail;

					if (t > 0 && t < size - 1 && filled (x - size + t + 2, y + size + t - 2)) goto fail;
					if (t > 0 && t < size - 1 && filled (x + size - t - 2, y + size + t - 2)) goto fail;
				}

				//printf ("Found diag %d %d\n", x, y);

				answer++;
				fail:;
			}

	return answer;
}

void solve()
{
	scanf ("%d %d", &nRows, &nColumns);

	for (int y = 0; y < nRows; y++)
	{
		char buffer[maxN];
		scanf ("%s", buffer);
		for (int x = 0; x < nColumns; x++)
			matrix[x][y] = buffer[x] == '1';
		//printf ("%s\n", buffer);
	}

	int nSquares = 0;
	nSquares += findRight();
	nSquares += findStupid();
	printf ("%d\n", nSquares);
}

int main()
{
	int nTests;
	scanf ("%d", &nTests);

	for (int i = 0; i < nTests; i++)
		solve();

	return 0;
}