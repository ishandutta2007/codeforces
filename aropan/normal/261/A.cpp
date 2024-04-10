#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }


const int MAXN = 100007;
int n, m;
int a[MAXN];
int v, ans;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	v = (int)1e+9;
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		v = min(v, x);
	}
	
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort(a, a + m);
	reverse(a, a + m);
	
	for (int i = 0; i < m; i++)
	{
		if (i % (v + 2) < v)
			ans += a[i];
	}
	printf("%d\n", ans);
	return 0;
}