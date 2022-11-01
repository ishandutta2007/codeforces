#include<bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, a[N];

int solve(int l, int r, int x)
{
	if (l == r) return a[l] != x;
	int pos = l, ans = r - l + 1;
	for (int i = l; i <= r; i++) if (a[i] < a[pos]) pos = i;
	int s = a[pos] - x;
	if (s >= ans) return ans;
	for (int i = l; i <= r; i++)
		if (a[i] != a[pos])
		{
			int j = i;
			while (j < r && a[j + 1] != a[pos]) j++;
			s += solve(i, j, a[pos]);
			i = j;
		}
	return min(ans, s);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	printf("%d\n", solve(1, n, 0));
	return 0;
}