#include <bits/stdc++.h>
#define M 200010

using namespace std;

int F[M], Pre[M], A[M], Last = 0;

int n, m, a, b;

void Writing(int x)
{
	if(!x) return;
	Writing(Pre[x]);
	printf("RUN %d\n", (A[Pre[x] + 1] - 1) - (A[Pre[x]] + 1));
	printf("JUMP %d\n", (A[x] + 1) - (A[Pre[x] + 1] - 1));
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	sort(A + 1, A + n + 1);
	if(A[n] == m)
	{
		puts("IMPOSSIBLE");
		return 0;
	}	
	A[0] = -1, F[0] = 1;
	if(A[1] - 1 - (A[0] + 1) < a)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i = 1; i <= n; i++)
		if(((A[i + 1] - 1) - (A[i] + 1) >= a || i == n) && (A[i] + 1) - (A[Last + 1] - 1) <= b)
			F[i] = 1, Pre[i] = Last, Last = i;
	if(!F[n])
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	Writing(n);
	if(A[n] + 1 != m) printf("RUN %d\n", m - A[n] - 1);
	return 0;
}