#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
#define N 100000 + 5
#define mp make_pair

int n, sz, X[N], Y[N], q[N];
bool ok = 0;
map <Pii, bool> Map;

inline int Rand(int p)
{
	return (rand() << 15 | rand()) % p;
}

inline LL Cross(int st, int t_1, int t_2)
{
	int x_1 = X[t_1] - X[st], y_1 = Y[t_1] - Y[st];
	int x_2 = X[t_2] - X[st], y_2 = Y[t_2] - Y[st];
	return 1LL * x_1 * y_2 - 1LL * x_2 * y_1;
}

bool Check(int u, int v)
{
	sz = 0;
	for (int i = 1; i <= n; i ++)
		if (Cross(i, u, v)) q[++ sz] = i;
	for (int i = 3; i <= sz; i ++)
		if (Cross(q[i], q[1], q[2])) return 0;
	return 1;
}

int main()
{
	srand(19260817);
	scanf("%d", &n);
	if (n <= 4)
	{
		puts("YES");
		return 0;
	}
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", X + i, Y + i);
	for (int i = 1; !ok && i <= 100 && i <= 1LL * n * (n - 1) / 2; i ++)
	{
		int u, v;
		do
		{
			u = Rand(n - 1) + 1;
			v = Rand(n - 1) + 1;
			if (v >= u) v ++;
			if (u > v) swap(u, v);
		} while (Map[mp(u, v)]);
		Map[mp(u, v)] = 1;
		ok = Check(u, v);
	}
	puts(ok ? "YES" : "NO");
	return 0;
}