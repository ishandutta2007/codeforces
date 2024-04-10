#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int n, m, k, x_1, y_1, x_2, y_2;
LL area;
bool flag;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if (2LL * n * m % k != 0)
		puts("NO");
	else
	{
		area = 2LL * n * m / k;
		if (n > m) swap(n, m), flag = 1;
		x_1 = n, x_2 = 1;
		y_2 = (area + n - 1) / n, y_1 = 1LL * x_1 * y_2 - area;
		if (flag)
		{
			swap(x_1, y_1);
			swap(x_2, y_2);
		}
		puts("YES");
		puts("0 0");
		printf("%d %d\n", x_1, y_1);
		printf("%d %d\n", x_2, y_2);
	}
	return 0;
}