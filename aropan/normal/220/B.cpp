#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
 #include <cmath>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 100007;

#define L first
#define R second

int n, m, k;
int a[MAXN];
int x[MAXN];
int f[MAXN];
pair <int, int> q[MAXN];
pair <int, int> v[MAXN];
int p[MAXN];
int ans[MAXN];
int sqrtm;
int res;

bool opr_sort(const int &i, const int &j)
{
	return v[i] < v[j];
}


void modify(int i, int v)
{
	if (f[i] == x[i]) res -= 1;
	f[i] += v;
	if (f[i] == x[i]) res += 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		x[i] = a[i];
	}
	sort(x, x + n);
	k = unique(x, x + n) - x;

	for (int i = 0; i < n; i++)
		a[i] = lower_bound(x, x + k, a[i]) - x;
	
	sqrtm = sqrt(m + 1);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &q[i].L, &q[i].R);
		q[i].L -= 1;
		q[i].R -= 1;
		v[i] = make_pair(q[i].L / sqrtm, q[i].R);
		p[i] = i;
	}

	sort(p, p + m, opr_sort);

	int l = 0, r = 0;
	res = 0;
	for (int I = 0; I < m; I++)
	{
		int i = p[I];
		while (r <= q[i].R) modify(a[r++], 1);
		while (q[i].R + 1 < r) modify(a[--r], -1);
		while (q[i].L < l) modify(a[--l], 1);
		while (l < q[i].L) modify(a[l++], -1);
		ans[i] = res;
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);

	fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}