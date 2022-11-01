#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int s = 0;
		for (int i = 2; i <= n; i++) s += a[i] == a[1];
		if (s == n - 1) printf("%d\n", n);
		else puts("1");
	}
	return 0;
}