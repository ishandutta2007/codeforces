#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, inv, Tree[N], A[N];

void Add(int x)
{
	for (; x <= n; x += (x & -x))
		Tree[x] ^= 1;
}

int Calc(int x)
{
	int res = 0;
	for (; x; x -= (x & -x))
		res ^= Tree[x];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = n; i; i --)
	{
		inv ^= Calc(A[i] - 1);
		Add(A[i]);
	}
	if (((n & 1) && (inv & 1)) || ((n + 1 & 1) && (inv + 1 & 1)))
		puts("Petr");
	else puts("Um_nik");
	return 0;
}