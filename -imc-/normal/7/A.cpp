#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	vector < vector <bool> > desk;

	desk.resize (8);
	for (int x = 0; x < 8; x++)
		desk[x].resize (8);

	int nRows = 0, nColumns = 0;

	for (int y = 0; y < 8; y++)
	{
		char buffer[256];
		scanf ("%s", buffer);

		bool thisRow = true;

		for (int x = 0; x < 8; x++)
		{
			desk[x][y] = buffer[x] == 'B';
			if (!desk[x][y]) thisRow = false;
		}

		if (thisRow) nRows++;
	}

	for (int x = 0; x < 8; x++)
	{
		bool thisColumn = true;

		for (int y = 0; y < 8; y++)
			if (!desk[x][y])
			{
				thisColumn = false;
				break;
			}

		if (thisColumn)
			nColumns++;
	}

	if (nColumns == 8 && nRows == 8)
		printf ("%i\n", nRows);
	else
		printf ("%i\n", nColumns + nRows);

	return 0;
}