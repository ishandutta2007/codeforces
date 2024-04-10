#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

struct point { int x, y; point(int x, int y): x(x), y(y) {} point(): x(0), y(0) {} };

typedef double ftype;

const int maxN = 2050;

int n;
int a[maxN][maxN];

void print()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x <= n; x++)
			printf("%c", a[x][y] ? '#' : '.');
		printf("\n");
	}
}

vector<point> bfs(int x, int y)
{
	vector<point> answer;
	
	deque<point> q;
	q.emplace_back(x, y);
	
	while (!q.empty())
	{
		point p = q.front();
		q.pop_front();
		
		x = p.x; y = p.y;
		
		if (x < 0 || y < 0 || x > n || y > n) continue;
		if (a[x][y] != 1) continue;
		a[x][y] = 2;
		answer.push_back(p);
		
		q.emplace_back(x + 1, y);
		q.emplace_back(x - 1, y);
		q.emplace_back(x, y + 1);
		q.emplace_back(x, y - 1);
	}
	
	return answer;
}

int main()
{
	bool readInput = true;
	bool doCircle = true;
	
	if (readInput)
		scanf("%d", &n);
	else
		n = 70;
		
	int r = 10;
	
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			if (readInput)
				scanf("%d", &a[x + 1][y + 1]);
			else
			{
				if (doCircle)
					a[x + 1][y + 1] = hypot(x - n / 2, y - n / 2) < r;
				else
					a[x + 1][y + 1] = max(abs(x - n / 2), abs(y - (n / 2))) < r;
				
				#if 1
				if (rand() % 100 < 20)
					a[x + 1][y + 1] = 1 - a[x + 1][y + 1];
				#endif
			}
		}
	
	if (!readInput)
		print();
	
	int nRectangles = 0, nCircles = 0;
	
	for (int y = 0; y <= n; y++)
		for (int x = 0; x <= n; x++)
			if (a[x][y] == 1)
			{
				vector<point> p = bfs(x, y);
				if (p.size() < 150 * 0.8)
				{
					for (point x: p)
						a[x.x][x.y] = 0;
					continue;
				}
				
				vector<int> xMin(maxN, maxN), xMax(maxN, -maxN);
				
				ftype cx = 0, cy = 0;
				for (point x: p)
				{
					cx += x.x; cy += x.y;
					xMin[x.y] = min(xMin[x.y], x.x);
					xMax[x.y] = max(xMax[x.y], x.x);
				}
				cx /= p.size(); cy /= p.size();
				
				vector<ftype> d;
				for (point x: p)
				{
					if (x.x == xMin[x.y] || x.x == xMax[x.y])
						d.push_back(hypot(x.x - cx, x.y - cy));
				}
				
				sort(d.begin(), d.end());
				
				//cout << "min " << dMin << " max " << dMax << endl;
				ftype ratio = d[d.size() - 4] / d[4];
				
				if (ratio > 1.30)
					nRectangles++;
				else
					nCircles++;
				//cout << "ratio " << ratio << endl;
			}
			
	if (!readInput)
		print();
	
	printf("%d %d\n", nCircles, nRectangles);
	
	return 0;
}