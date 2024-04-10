#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10 + 5

int n, A[N];
bool ok = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1; ok && i <= n; i ++)
	{
		scanf("%d", A + i);
		if (i > 1 && abs(A[i] - A[i - 1]) > 1) ok = 0;
	}
	puts(ok ? "YES" : "NO");
	return 0;
}