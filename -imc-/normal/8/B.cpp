#include <cstdio>
#include <cstring>

using namespace std;

const int maxN = 105;
bool field[maxN * 2][maxN * 2];
char directions[maxN];

int main()
{
	scanf ("%s", directions);

	int x = maxN, y = maxN;

	int numDirections = strlen (directions);
	for (int i = 0; i < numDirections; i++)
	{
		int nc = 0;
		if (field[x][y])
			nc = 100;

		field[x][y] = true;

		if (directions[i] == 'U') y--;
		if (directions[i] == 'D') y++;
		if (directions[i] == 'L') x--;
		if (directions[i] == 'R') x++;

		if (field[x + 1][y]) nc++;
		if (field[x - 1][y]) nc++;
		if (field[x][y + 1]) nc++;
		if (field[x][y - 1]) nc++;

		if (nc >= 2)
		{
			printf ("BUG\n");
			return 0;
		}
	}

	printf ("OK\n");

	return 0;
}