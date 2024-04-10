#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
#define mp make_pair

int n;

struct Point
{
	int x, y;
	Point (int x, int y) : x(x), y(y) {}
	void out() const
	{
		printf("%d %d\n", x, y);
	}
	bool operator < (const Point& obj) const
	{
		return mp(x, y) < mp(obj.x, obj.y);
	}
};

vector <Point> A;

const int Fx[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
const int INF = 0x3f3f3f3f;

int Generate()
{
	map <Point, int> Map;
	for (const Point& p : A)
		Map[p] = -INF;
	queue <Point> Q;
	for (const Point& p : A)
		for (int k = 0; k < 8; k ++)
		{
			int tx = p.x + Fx[k][0], ty = p.y + Fx[k][1];
			if ((++ Map[Point(tx, ty)]) >= 4)
				Q.push(Point(tx, ty));
		}
	int res = A.size();
	while (!Q.empty())
	{
		Point p = Q.front();
		Map[p] = -INF;
		res ++;
		Q.pop();
		for (int k = 0; k < 8; k ++)
		{
			int tx = p.x + Fx[k][0], ty = p.y + Fx[k][1];
			if ((++ Map[Point(tx, ty)]) >= 4)
				Q.push(Point(tx, ty));
		}
	}
	return res;
}

// #define DEBUG

int main()
{
#ifndef DEBUG
	scanf("%d", &n);
#else
	for (n = 1; n <= 1000; n ++)
#endif
	{
		A.clear();
		A.push_back(Point(0, 0));
		for (int i = 1; i <= (n + 2 >> 2); i ++)
			A.push_back(Point(-i, 0));
		for (int i = 1; i <= (n + 1 >> 2); i ++)
			A.push_back(Point(0, i));
		for (int i = 1; i <= (n >> 2); i ++)
			A.push_back(Point(i, 0));
		for (int i = 1; i <= (n - 1 >> 2); i ++)
			A.push_back(Point(0, -i));
		
	#ifndef DEBUG
		for (const Point& p : A)
			p.out();
	#else
		int cnt = Generate();
		if (cnt >= n * n / 10)
			fprintf(stderr, "%d : OK, %d Generated\n", n, cnt);
		else
		{
			fprintf(stderr, "%d : WA, %d Generated\n", n, cnt);
			break ;
		}
	#endif
	}
	return 0;
}