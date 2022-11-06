#include <cstdio>
#include <algorithm>
using namespace std;
#define N 132674 + 5

int n, cnt, sz_y, ok, X_1[N], Y_1[N], X_2[N], Y_2[N], Ord[N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d%d%d", X_1 + i, Y_1 + i, X_2 + i, Y_2 + i);
		Ord[i] = i;
	}
	srand(19260817);
	do
	{
		random_shuffle(Ord + 1, Ord + n + 1);
		ok = 2;
		int x_1 = X_1[Ord[1]], y_1 = Y_1[Ord[1]], x_2 = X_2[Ord[1]], y_2 = Y_2[Ord[1]];
		for (int i = 2; ok && i <= n; i ++)
		{
			int _x_1 = X_1[Ord[i]], _y_1 = Y_1[Ord[i]], _x_2 = X_2[Ord[i]], _y_2 = Y_2[Ord[i]];
			_x_1 = max(x_1, _x_1), _y_1 = max(y_1, _y_1);
			_x_2 = min(x_2, _x_2), _y_2 = min(y_2, _y_2);
			if (_x_1 > _x_2 || _y_1 > _y_2) ok --;
			else x_1 = _x_1, y_1 = _y_1, x_2 = _x_2, y_2 = _y_2;
		}
		if (ok) printf("%d %d\n", x_1, y_1);
	} while (!ok);
	return 0;
}