#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 10000 + 5
#define M 32768
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, Q[N];
bitset <N> Stack[N], Ans;
vector <int> Vec[M];

void Add(int x, int l, int r, int s, int t, int k)
{
	if (l == s && r == t)
	{
		Vec[x].push_back(k);
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid) Add(ls(x), l, mid, s, t, k);
	else if (s > mid) Add(rs(x), mid + 1, r, s, t, k);
	else Add(ls(x), l, mid, s, mid, k), Add(rs(x), mid + 1, r, mid + 1, t, k);
}

void dfs(int x, int l, int r, int dep)
{
	Stack[dep] = Stack[dep - 1];
	for (int d : Vec[x])
		Stack[dep] |= (Stack[dep] << d);
	Ans |= Stack[dep];
	if (l == r) return ;
	int mid = l + r >> 1;
	dfs(ls(x), l, mid, dep + 1);
	dfs(rs(x), mid + 1, r, dep + 1);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1, l, r, x; i <= q; i ++)
	{
		scanf("%d%d%d", &l, &r, &x);
		Add(1, 1, n, l, r, x);
	}
	Stack[0][0] = 1;
	dfs(1, 1, n, 1);
	for (int i = 1; i <= n; i ++)
		if (Ans[i]) Q[++ Q[0]] = i;
	printf("%d\n", Q[0]);
	for (int i = 1; i <= Q[0]; i ++)
		printf("%d%c", Q[i], i == Q[0] ? '\n' : ' ');
	return 0;
}