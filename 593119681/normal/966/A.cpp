#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define INF 0x7fffffff

int n, m, l, e, v, q, L[N], E[N];

int main()
{
	scanf("%d%d%d%d%d", &n, &m, &l, &e, &v);
	for (int i = 1; i <= l; i ++)
		scanf("%d", L + i);
	for (int i = 1; i <= e; i ++)
		scanf("%d", E + i);
	scanf("%d", &q);
	for (int i = 1, x_1, y_1, x_2, y_2; i <= q; i ++)
	{
		int Min = INF;
		scanf("%d%d%d%d", &y_1, &x_1, &y_2, &x_2);
		if (y_1 == y_2) Min = abs(x_1 - x_2);
		{
			int l_l = lower_bound(L + 1, L + l + 1, x_1) - L;
			int l_r = lower_bound(L + 1, L + l + 1, x_1) - L - 1;
			if (l_l <= l) Min = min(Min, abs(y_1 - y_2) + abs(x_1 - L[l_l]) + abs(x_2 - L[l_l]));
			if (l_r > 0) Min = min(Min, abs(y_1 - y_2) + abs(x_1 - L[l_r]) + abs(x_2 - L[l_r]));
			int e_l = lower_bound(E + 1, E + e + 1, x_1) - E;
			int e_r = lower_bound(E + 1, E + e + 1, x_1) - E - 1;
			if (e_l <= e) Min = min(Min, (abs(y_1 - y_2) + v - 1) / v + abs(x_1 - E[e_l]) + abs(x_2 - E[e_l]));
			if (e_r > 0) Min = min(Min, (abs(y_1 - y_2) + v - 1) / v + abs(x_1 - E[e_r]) + abs(x_2 - E[e_r]));
		}
		{
			int l_l = lower_bound(L + 1, L + l + 1, x_2) - L;
			int l_r = lower_bound(L + 1, L + l + 1, x_2) - L - 1;
			if (l_l <= l) Min = min(Min, abs(y_1 - y_2) + abs(x_1 - L[l_l]) + abs(x_2 - L[l_l]));
			if (l_r > 0) Min = min(Min, abs(y_1 - y_2) + abs(x_1 - L[l_r]) + abs(x_2 - L[l_r]));
			int e_l = lower_bound(E + 1, E + e + 1, x_2) - E;
			int e_r = lower_bound(E + 1, E + e + 1, x_2) - E - 1;
			if (e_l <= e) Min = min(Min, (abs(y_1 - y_2) + v - 1) / v + abs(x_1 - E[e_l]) + abs(x_2 - E[e_l]));
			if (e_r > 0) Min = min(Min, (abs(y_1 - y_2) + v - 1) / v + abs(x_1 - E[e_r]) + abs(x_2 - E[e_r]));
		}
		printf("%d\n", Min);
	}
	return 0;
}