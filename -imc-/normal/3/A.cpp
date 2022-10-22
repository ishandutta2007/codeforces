#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void readPos (int& x, int& y)
{
	char c;
	scanf (" %c%i", &c, &y);
	x = c - 'a';
}

int main()
{
	int x0, y0, x1, y1;
	readPos (x0, y0);
	readPos (x1, y1);

	int dx = x1 - x0, dy = y1 - y0;

	printf ("%i\n", max (abs (dx), abs (dy)));

	while (true)
	{
		bool goUp = false, goDown = false, goLeft = false, goRight = false;

		if (dx > 0) { dx--; goRight = true; }
		if (dx < 0) { dx++; goLeft = true;  }
		if (dy > 0) { dy--; goUp = true;    }
		if (dy < 0) { dy++; goDown = true;  }

		if (!goUp && !goDown && !goLeft && !goRight) return 0;

		if (goLeft) putchar ('L');
		if (goRight) putchar ('R');
		if (goUp) putchar ('U');
		if (goDown) putchar ('D');
		putchar ('\n');
	}

	return 0;
}