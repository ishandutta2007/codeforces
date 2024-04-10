#include <cstdio>
#include <algorithm>

using namespace std;

const int maxN = 50;
int ground[maxN][maxN];
int nCornerEnd[maxN][maxN][maxN][maxN];
int prefixSum[maxN][maxN];
int answer[maxN][maxN][maxN][maxN];

int main()
{
	#ifdef LOCAL
	freopen ("b.in", "r", stdin);
	#endif
	
	int nRows, nColumns, nQueries;
	scanf ("%d %d %d", &nRows, &nColumns, &nQueries);
	
	for (int y = 1; y <= nRows; y++)
	{
		char row[256];
		scanf ("%s", row);
	
		for (int x = 1; x <= nColumns; x++)
		{
			ground[x][y] = row[x - 1] == '1';
			answer[x][y][x][y] = 1 - ground[x][y];
		}
	}
	
	for (int x = 1; x <= nColumns; x++)
		for (int y = 1; y <= nRows; y++)
			prefixSum[x][y] = prefixSum[x - 1][y] + prefixSum[x][y - 1] - prefixSum[x - 1][y - 1] + ground[x][y];
	
	for (int cx = 1; cx <= nColumns; cx++)
		for (int cy = 1; cy <= nRows; cy++)
			for (int w = 1; w <= nColumns; w++)
				for (int h = 1; h <= nRows; h++)
				{
					if (w > cx || h > cy)
					{
						nCornerEnd[cx][cy][w][h] = nCornerEnd[cx][cy][min (cx, w)][min (cy, h)];
						continue;
					}
					
					int add = (prefixSum[cx][cy] - prefixSum[cx - w][cy] - prefixSum[cx][cy - h] + prefixSum[cx - w][cy - h]) == 0;
					nCornerEnd[cx][cy][w][h] = nCornerEnd[cx][cy][w - 1][h] + nCornerEnd[cx][cy][w][h - 1] - nCornerEnd[cx][cy][w - 1][h - 1] + add;
				}
	
			
	for (int w = 1; w <= nColumns; w++)
		for (int h = 1; h <= nRows; h++)
		{
			if (w == 1 && h == 1) continue;
			if (w == 1)
			{
				for (int x = 1; x <= nColumns - w + 1; x++)
					for (int y = 1; y <= nRows - h + 1; y++)
						answer[x][y][x][y + h - 1] = answer[x][y][x][y + h - 2] + nCornerEnd[x][y + h - 1][w][h];
			}
			else if (h == 1)
			{
				for (int y = 1; y <= nRows - h + 1; y++)
					for (int x = 1; x <= nColumns - w + 1; x++)
						answer[x][y][x + w - 1][y] = answer[x][y][x + w - 2][y] + nCornerEnd[x + w - 1][y][w][h];
			}
			else
			{			
				for (int x = 1; x <= nColumns - w + 1; x++)
					for (int y = 1; y <= nRows - h + 1; y++)
						answer[x][y][x + w - 1][y + h - 1] = answer[x][y][x + w - 2][y + h - 1] + answer[x][y][x + w - 1][y + h - 2] - answer[x][y][x + w - 2][y + h - 2] + nCornerEnd[x + w - 1][y + h - 1][w][h];
			}
		}
		
	for (int i = 0; i < nQueries; i++)
	{
		int x0, y0, x1, y1;
		scanf ("%d %d %d %d", &y0, &x0, &y1, &x1);
		printf ("%d\n", answer[x0][y0][x1][y1]);
		//printf ("%d %d %d %d\n", answer[x0][y0][x1 - 1][y1], answer[x0][y0][x1][y1 - 1], answer[x0][y0][x1 - 1][y1 - 1], nCornerEnd[x1][y1][x1][y1]);
	}
	
	return 0;
}