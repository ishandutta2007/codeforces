#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
	int n;
	scanf ("%i", &n);

	for (int i = 0; i < n; i++)
	{
		char cellName[256];
		scanf ("%s", cellName);

		int row, column;
		if (sscanf (cellName, "R%iC%i", &row, &column) == 2)
		{
			vector <char> columnName;
			while (true)
			{
				if (column >= 1 && column <= 26)
				{
					columnName.push_back ('A' + column - 1);
					break;
				}
				else
				{
					columnName.push_back ('A' + (column - 1) % 26);
					column = (column - (column - 1) % 26) / 26;
				}
			}

			for (int i = columnName.size() - 1; i >= 0; i--)
				putchar (columnName[i]);
			printf ("%i\n", row);
		}
		else
		{
			int length = 0;
			column = 0;
			while (isalpha (cellName[length]))
			{
				column *= 26;
				column += (cellName[length] - 'A' + 1);
				length++;
			}
			sscanf (cellName + length, "%i", &row);
			printf ("R%iC%i\n", row, column);
		}
	}

	return 0;
}