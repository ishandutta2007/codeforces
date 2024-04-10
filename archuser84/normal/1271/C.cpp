#include <iostream>
#include <string>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

struct coo
{
	int x = 0;
	int y = 0;
};

int main()
{
	int n;
	coo S;
	cin >> n >> S.x >> S.y;
	int u = 0, d = 0, l = 0, r = 0;
	for (LoopN)
	{
		coo h;
		cin >> h.x >> h.y;
		if (h.x > S.x)
			++r;
		if (h.x < S.x)
			++l;
		if (h.y > S.y)
			++u;
		if (h.y < S.y)
			++d;
	}


	int max = u;
	int maxd = 1;
	if (d > max)
	{
		max = d;
		maxd = 2;
	}
	if (l > max)
	{
		max = l;
		maxd = 3;
	}
	if (r > max)
	{
		max = r;
		maxd = 4;
	}
	cout << max << '\n';
	switch (maxd)
	{
	case 1: printf("%i %i\n", S.x, S.y + 1); break;
	case 2: printf("%i %i\n", S.x, S.y - 1); break;
	case 3: printf("%i %i\n", S.x - 1, S.y); break;
	case 4: printf("%i %i\n", S.x + 1, S.y); break;
	}
}