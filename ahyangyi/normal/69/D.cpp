#include <stdio.h>
#include <map>

using namespace std;

int x, y, d, n;
int X1[200], Y1[200];

struct xx
{
	int x, y, a, b;

	xx () {}
	xx (int _x, int _y, int _a, int _b) : x(_x), y(_y), a(_a), b(_b) {}
};

map<xx, bool> M;

bool operator < (const xx& a, const xx& b)
{
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	if (a.a != b.a) return a.a < b.a;
	return a.b < b.b;
}

bool dfs (xx x)
{
	if (M.find(x) != M.end())
		return M[x];
	bool ans = false;
	if (x.a)
		ans |= !dfs(xx(x.y,x.x,x.b,0));
	for (int i = 0; i < d && !ans; i ++)
	{
		int x2, y2;

		x2 = x.x + X1[i];
		y2 = x.y + Y1[i];

		if (x2 * x2 + y2 * y2 <= n * n)
			ans |= !dfs(xx(x2, y2, x.a, x.b));
	}

//	printf ("dfs %d %d %d %d = %d\n", x.x, x.y, x.a, x.b, (int) ans);
	return (M[x] = ans);
}

int main ()
{
	scanf ("%d%d%d%d", &x, &y, &d, &n);
	for (int i = 0; i < d; i ++)
		scanf ("%d%d", X1 + i, Y1 + i);

	if (dfs (xx(x,y,1,1)))
		printf ("Anton\n");
	else
		printf ("Dasha\n");

	return 0;
}