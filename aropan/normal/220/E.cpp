#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }


const int MAXN = 100007;

int a[MAXN];
int x[MAXN];
int s[2][MAXN];
int c[2];
int n, m;
long long k;
long long inv = 0;

int findsum(int *s, int x)
{
	int res = 0;
	for (int i = x; i <= m; i += i & -i)
		res += s[i];
	return res;
}

void modify(int *s, int x, int d)
{
	for (int i = x; 1 <= i; i -= i & -i)
		s[i] += d;
}

void addl(int x, int d)
{	
	inv += d * findsum(s[0], x + 1);
	modify(s[0], x, d);
	c[0] += d;
	inv += d * (c[1] - findsum(s[1], x));
}

void addr(int x, int d)
{	
	inv += d * (c[1] - findsum(s[1], x));
	modify(s[1], x, d);
	c[1] += d;
	inv += d * findsum(s[0], x + 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		x[i] = a[i];
	}

	sort(x, x + n);
	m = unique(x, x + n) - x;

	for (int i = 0; i < n; i++)
		a[i] = lower_bound(x, x + m, a[i]) - x + 1;

	long long ans = 0;
	for (int i = 0, j = n; i < n; i++)
	{
		addl(a[i], 1);
		while (i + 1 < j && inv <= k) addr(a[--j], 1);
		while (j <= i || j < n && inv > k) addr(a[j++], -1);
		ans += n - j;
	}
	cout << ans << endl;
	fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}