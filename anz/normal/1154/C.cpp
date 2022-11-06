#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>

using namespace std;

int foods[7] = { 0,1,2,0,2,1,0 };

int main() {
	int a[3];
	scanf("%d%d%d", &a[0], &a[1], &a[2]);

	int result = min(min(a[0] / 3, a[1] / 2), a[2] / 2);

	a[0] -= 3 * result;
	a[1] -= 2 * result;
	a[2] -= 2 * result;

	//printf("%d\n", result);

	int maxDay = 0;
	for (int i = 0; i < 7; i++)
	{
		int ta[3];
		ta[0] = a[0], ta[1] = a[1], ta[2] = a[2];
		int curDay = 0;
		for (int j = 0; j < 7; j++)
		{
			int curFood = foods[(i + j) % 7];
			if (ta[curFood] > 0)
				ta[curFood]--, curDay++;
			else
				break;
		}
		maxDay = max(maxDay, curDay);
	}
	printf("%d", result*7 + maxDay);
}