#include <cstdio>
#include <cstdlib>

using namespace std;

char field[10][10];

bool isFilled (int sx, int sy, int vx, int vy)
{
	char start = field[sx][sy];

	for (int i = 0; i < 2; i++)
	{
		sx += vx + 3;
		sx %= 3;
		sy += vy + 3;
		sy %= 3;

		if (field[sx][sy] != start) return false;
	}

	return true;
}

bool wins (char c)
{
	bool w =  (field[0][0] == c && isFilled (0, 0, 1, 1)) || (field[2][0] == c && isFilled (2, 0, -1, 1));
	for (int t = 0; t < 3; t++)
		if ((field[0][t] == c && isFilled (0, t, 1, 0)) || (field[t][0] == c && isFilled (t, 0, 0, 1)))
			return true;
	return w;
}

void verdict (const char* s)
{
	printf ("%s\n", s);
	exit (0);
}

int main()
{
	int nFirst = 0, nSecond = 0;

	for (int y = 0; y < 3; y++)
	{
		char buffer[10];
		scanf ("%s", buffer);
		for (int x = 0; x < 3; x++)
		{
			field[x][y] = buffer[x];
			if (field[x][y] == 'X') nFirst++;
			if (field[x][y] == '0') nSecond++;
		}
	}

	if (nSecond > nFirst || nFirst > nSecond + 1)
		verdict ("illegal");

	bool first = wins ('X'), second = wins ('0');
	if (first && second)
		verdict ("illegal");

	if (first && (nSecond + 1 != nFirst)) verdict ("illegal");
	if (second && (nSecond != nFirst)) verdict ("illegal");

	if (first)  verdict ("the first player won");
	if (second) verdict ("the second player won");
	if (nFirst + nSecond == 9) verdict ("draw");

	if (nSecond == nFirst)
		verdict ("first");
	else
		verdict ("second");

	return 0;
}