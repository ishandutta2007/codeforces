#include <cstdio>
#include <algorithm>
using namespace std;

int x1, x2, y1, y2;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%c%c\n%c%c", &x1, &y1, &x2, &y2);

	printf("%d\n", max(abs(x2 - x1), abs(y2 - y1)));

	while (x1 != x2 || y1 != y2)
	{
		if (x1 < x2) { printf("R"); x1++; } else
		if (x1 > x2) { printf("L"); x1--; }

		if (y1 < y2) { printf("U"); y1++; } else
		if (y1 > y2) { printf("D"); y1--; }

		printf("\n");
	}



	return 0;
}