#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, m = -1, A[N], No[N];
bool ok = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1; ok && i <= n; i ++)
	{
		scanf("%d", A + i);
		if (i == 1) continue ;
		if (abs(A[i - 1] - A[i]) == 1)
		{
			int id = min(A[i - 1], A[i]);
			No[++ No[0]] = id;
		}
		else
		{
			int id = abs(A[i - 1] - A[i]);
			if (~m && m != id) ok = 0;
			else m = id;
		}
	}
	if (!~m) m = 1000000000;
	ok &= (m != 0);
	for (int i = 1; ok && i <= No[0]; i ++)
		ok = (No[i] % m != 0);
	if (ok)
	{
		puts("YES");
		printf("1000000000 %d\n", m);
	}
	else puts("NO");
	return 0;
}