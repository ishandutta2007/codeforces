#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, m, L[N], R[N], Last[N], Tree[2][N];
bool Flag[N];

void Add(int id, int x, int k)
{
	for (; x; x -= (x & -x))
		Tree[id][x] += k;
}

int Calc(int id, int x)
{
	int res = 0;
	for (; x < N; x += (x & -x))
		res += Tree[id][x];
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		L[i] = R[i] = i;
	for (int i = 1, x; i <= m; i ++)
	{
		scanf("%d", &x);
		L[x] = 1;
		if (!Last[x])
			R[x] = R[x] + Calc(1, x);
		else
		{
			R[x] = max(R[x], Calc(0, Last[x]));
			Add(0, Last[x], -1);
		}
		Last[x] = i;
		Add(0, i, 1);
		if (!Flag[x])
			Add(1, x, 1);
		Flag[x] = 1;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (!Flag[i])
			R[i] = R[i] + Calc(1, i);
		else R[i] = max(R[i], Calc(0, Last[i]));
	}
	for (int i = 1; i <= n; i ++)
		printf("%d %d\n", L[i], R[i]);
	return 0;
}