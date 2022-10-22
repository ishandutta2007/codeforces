#include <cstdio>
#include <vector>

using namespace std;

const int maxN = 1005, infinity = 10000000;

int N;
int two[maxN][maxN], five[maxN][maxN];

int matrix[maxN][maxN], m[maxN][maxN];
int turn[maxN][maxN];

vector <char> theAnswer;
int answerCost;

inline void relax (int& x, int v, int& d, int dSet)
{
	if (v < x)
	{
		x = v;
		d = dSet;
	}
}

void relaxAnswer()
{
	turn[0][0] = -1;

	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
		{
			if (!x && !y) continue;

			int right = x > 0 ? matrix[x - 1][y] : infinity,
				down  = y > 0 ? matrix[x][y - 1] : infinity;

			if (right < down)
			{
				turn[x][y] = 0;
				matrix[x][y] += right;
			}
			else
			{
				turn[x][y] = 1;
				matrix[x][y] += down;
			}
		}

	if (matrix[N - 1][N - 1] < answerCost)
	{
		answerCost = matrix[N - 1][N - 1];
		theAnswer.resize (2 * N - 2);

		int cx = N - 1, cy = N - 1;
		int i = 0;
		while (turn[cx][cy] != -1)
		{
			theAnswer[2 * N - 2 - i - 1] = (turn[cx][cy] ? 'D' : 'R');
			if (turn[cx][cy])
				cy--;
			else
				cx--;

			i++;
		}
	}
}

int main()
{
	scanf ("%i", &N);
	answerCost = infinity;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			scanf ("%i", &m[x][y]);

			if (m[x][y] == 0)
			{
				if (answerCost > 1)
				{
					answerCost = 1;
					theAnswer.clear();

					for (int t = 0; t < x; t++)
						theAnswer.push_back ('R');
					for (int t = 0; t < y; t++)
						theAnswer.push_back ('D');
					for (int t = 0; t < N - x - 1; t++)
						theAnswer.push_back ('R');
					for (int t = 0; t < N - y - 1; t++)
						theAnswer.push_back ('D');
				}

				two[x][y] = five[x][y] = infinity;
			}
			else
			{
				while (m[x][y] % 2 == 0) { m[x][y] /= 2; two [x][y]++; }
				while (m[x][y] % 5 == 0) { m[x][y] /= 5; five[x][y]++; }
			}
		}

	for (int t = 0; t < 2; t++)
	{
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				matrix[x][y] = t ? two[x][y] : five[x][y];

		relaxAnswer();
	}

	printf ("%i\n", answerCost);
	for (int i = 0; i < (int)theAnswer.size(); i++)
		printf ("%c", theAnswer[i]);
	printf ("\n");

	return 0;
}