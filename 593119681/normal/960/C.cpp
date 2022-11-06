#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int x, d;
LL Ans[N];

void Solve(int ret, int del, LL cur)
{
	if (!ret) return ;
	int i = 1;
	for (; (1LL << i) - 1 <= ret; i ++) ;
	i --;
	ret -= (1LL << i) - 1;
	for (int j = 1; j <= i; j ++)
		Ans[++ Ans[0]] = cur;
	Solve(ret, del, cur + del);
}

int main()
{
	scanf("%d%d", &x, &d);
	Solve(x, d, 1);
	for (int i = 0; i <= Ans[0]; i ++)
		printf("%lld%c", Ans[i], i % Ans[0] == 0 ? '\n' : ' ');
	return 0;
}