#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int Case, n, mn, mx, A[N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		mn = mx = 1;
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", A + i);
			if (A[i] > A[mx])
				mx = i;
			if (A[i] < A[mn]) 
				mn = i;
		}
		printf("%d %d\n", mn, mx);
	}
	return 0;
}