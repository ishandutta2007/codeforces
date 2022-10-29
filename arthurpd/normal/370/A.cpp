#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int x1, y1, x2, y2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	int ans[3];
	ans[0] = int(x1 != x2) + int(y1 != y2);
	ans[1] = int((x1+y1) != (x2+y2)) + int((x1-y1) != (x2-y2));
	ans[2] = max(abs(x1 - x2), abs(y1 - y2));
	if((x1+y1) % 2 != (x2+y2) % 2)
		ans[1] = 0;
	printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}