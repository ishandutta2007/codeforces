#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int mx = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] <= i) mx = i;
		printf("%d\n", mx + 1);
	}
	return 0;
}