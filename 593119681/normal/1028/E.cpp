#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 140582 + 5

int n, pos, Max, A[N];
LL Ans[N];

inline int Pre(int i)
{
	return i == 1 ? n : i - 1;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Max = max(Max, A[i]);
	}
	if (Max == 0)
	{
		puts("YES");
		for (int i = 1; i <= n; i ++)
			printf("%lld%c", 1LL, i == n ? '\n' : ' ');
		return 0;
	}
	for (int i = 1; i <= n; i ++)
	{
		int _i = Pre(i);
		if ((A[_i] < A[i]) && (!pos || A[pos] < A[i]))
			pos = i;
	}
	if (!pos) puts("NO");
	else
	{
		puts("YES");
		Ans[pos] = A[pos];
		for (int i = Pre(pos), j = pos; i != pos; j = i, i = Pre(i))
		{
			Ans[i] = Ans[j] + A[i];
			if (j == pos) Ans[i] += Ans[j];
		}
		for (int i = 1; i <= n; i ++)
			printf("%lld%c", Ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}