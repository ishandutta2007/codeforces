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
int n;
int a[MAXN];
int b[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		b[i] = a[i];
	sort(a, a + n);

	int res = 0;
	for (int i = 0; i < n; i++)
		res += a[i] != b[i];
	puts(res < 3? "YES" : "NO");

	fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}