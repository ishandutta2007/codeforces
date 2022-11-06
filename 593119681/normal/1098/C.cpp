#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, A[N], Dep[N], Deg[N], Fa[N];
LL s;

bool Check(int k)
{
	LL tot = 1LL * n * (n + 1) / 2;
	if (tot < s)
		return 0;
	for (int i = 1; i <= n; i ++)
		A[i] = 1;
	for (int i = n, last = (k == 1 ? n : 2); tot > s && last < i; i --)
	{
		if (i - last <= tot - s)
		{
			tot -= (i - last), A[i] --, A[last] ++;
			if (1LL * A[last - 1] * k == A[last])
				last ++;
		}
		else
		{
			A[i] --, A[i - (tot - s)] ++;
			tot = s;
		}
	}
	return tot == s;
}

void Construct(int k)
{
	Dep[1] = 1, Deg[1] = 0;
	for (int i = 2, l, r = 1, sz = 1; i <= n; sz += A[i], i ++)
	{
		for (l = r; r <= n && Dep[r] == i - 1; r ++) ;
		for (int x = sz + 1, last = l; x <= sz + A[i]; x ++)
		{
			Dep[x] = i, Fa[x] = last, Deg[last] ++;
			if (Deg[last] == k)
				last ++;
		}
	}
}

int main()
{
	scanf("%d%lld", &n, &s);
	int l = 1, r = n;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (Check(mid))
			r = mid;
		else l = mid + 1;
	}
	if (l == n)
		puts("No");
	else
	{
		puts("Yes");
		Check(l);
		Construct(l);
		for (int i = 2; i <= n; i ++)
			printf("%d%c", Fa[i], i == n ? '\n' : ' ');
	}
	return 0;
}