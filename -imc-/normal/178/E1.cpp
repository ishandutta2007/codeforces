#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxN = 2050;
int a[maxN][maxN];
int b[maxN][maxN];

int c[maxN][maxN];

int n;

void parasite()
{
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			b[x][y] = a[x][y] || a[x - 1][y] || a[x][y - 1] || a[x + 1][y] || a[x][y + 1];
	
	memcpy(a, b, sizeof(b));
}

int main()
{
	bool readInput = true;
	bool doCircle = false;
	
	if (readInput)
		scanf("%d", &n);
	else
		n = 70;
	
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			if (readInput)
				scanf("%d", &a[x + 1][y + 1]);
			else
			{
				if (doCircle)
					a[x + 1][y + 1] = hypot(x - n / 2, y - n / 2) < n / 4;
				else
					a[x + 1][y + 1] = max(abs(x - n / 2), abs(y - (n / 2))) < n / 4;
			}
		}
		
	if (!readInput)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x <= n; x++)
				printf("%c", a[x][y] ? '#' : '.');
			printf("\n");
		}
	}
			
	for (int i = 0; i < 4; i++) parasite();
	
	int nRectangles = 0, nCircles = 0;
	
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			if (!c[x][y] && a[x][y])
			{
				struct point { int x, y; point(int x, int y): x(x), y(y) {} point(): x(0), y(0) {} };
				
				deque<point> bfs;
				bfs.push_back(point(x, y));
				
				vector<point> border;
				
				while (!bfs.empty())
				{
					point p = bfs.front();
					bfs.pop_front();
					if (p.x <= 0 || p.y <= 0 || p.x > n || p.y > n) continue;
					if (c[p.x][p.y]) continue;
					if (!a[p.x][p.y]) continue;
					c[p.x][p.y] = 1;
					
					if (!a[p.x + 1][p.y] || !a[p.x - 1][p.y] || !a[p.x][p.y - 1] || !a[p.x][p.y + 1])
						border.push_back(p);
					
					bfs.push_back(point(p.x + 1, p.y));
					bfs.push_back(point(p.x - 1, p.y));
					bfs.push_back(point(p.x, p.y + 1));
					bfs.push_back(point(p.x, p.y - 1));
				}
				
				typedef double ftype;
				
				ftype cx = 0, cy = 0;
				for (auto p: border)
				{
					cx += p.x;
					cy += p.y;
				}
				
				cx /= border.size();
				cy /= border.size();
				
				ftype dMin = 1e9, dMax = -1e9;
				for (auto p: border)
				{
					ftype d = hypot(p.x - cx, p.y - cy);
					dMin = min(dMin, d);
					dMax = max(dMax, d);
				}
				
				ftype ratio = dMax / dMin;
				//cout << "ratio " << ratio << " dmin " << dMin << " dmax " << dMax << endl;
				
				if (ratio > (sqrt(2) + 1) / 2)
					nRectangles++;
				else
					nCircles++;
			}
	
	printf("%d %d\n", nCircles, nRectangles);
	
	return 0;
}