#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100007;

int n;
pair <int, int> a[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);

	sort(a, a + n);
	int ans = 0;
	for (int i = 0, j = 0; i < n; i = j)
	{
		while (j < n && a[i] == a[j]) j++;
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
	return 0;
}