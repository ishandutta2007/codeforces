#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


const int MAXN = 100005;

long long a[MAXN];
int n, m, k;
int upd[MAXN];
long long ans[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &k);
		if (!upd[k])
		{
			upd[k] = true;
			long long &res = ans[k];
			res = 0;
			for (long long i = 1, j = 1, l = k; i < n; i += l, l *= k, j += 1)
				res += j * (a[min(i + l, (long long)n)] - a[i]);
		}
		cout << ans[k];
		if (m) printf(" ");
	}
	printf("\n");
	return 0;
}